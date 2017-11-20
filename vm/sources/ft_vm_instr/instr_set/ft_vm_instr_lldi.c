/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_lldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:30:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 15:32:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation

void			ft_vm_instr_lldi(unsigned char arena[],
									t_dead_pool *dead_pool,
									int option[])
{
	int					i;
	unsigned int		address;
	unsigned char		*ptr;
	extern uint8_t		g_direct_jump_table_from_instr[17];

	/* Set up a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	address = 0;
	i = 0;
	/* Read arguments */
	while (i < (dead_pool->i_champ->instr.op->nb_args - 1))
	{
		if (dead_pool->i_champ->instr.op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				ft_vm_instr_fail(dead_pool, CARRY_CHANGE);
				return ;
			}
			address += dead_pool->i_champ->reg[*ptr];
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_IND)
			address += MOD(dead_pool->i_champ->pc - arena
								+ ft_instruction_get_data(2, ptr));
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_DIR)
			address += MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr));
		++i;
		ptr += dead_pool->i_champ->instr.arg_jump[i];
	}
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(dead_pool, CARRY_CHANGE);
		return ;
	}
	/* Load the value in a register */
	dead_pool->i_champ->reg[*ptr] = arena[MOD(dead_pool->i_champ->pc
									- arena + address)];
	/* Move the Program Counter */
	dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0]
	+ dead_pool->i_champ->instr.arg_jump[1] + dead_pool->i_champ->instr.arg_jump[2];
	/* Wrie in the logfile */
	OPTION_LOG ? ft_vm_log_lldi(dead_pool, ptr, address) : 0;
	/* Waiting time until the next instruction */
	dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
	/* Change the carry */
	dead_pool->i_champ->carry = 0;
}
