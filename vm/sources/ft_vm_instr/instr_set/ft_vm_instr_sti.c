/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:56:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/16 15:58:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO: presentation
/*
* brief      		Execute sti : Take a registry and 2 indexes
* (potentially registries), add the two indexes and use this result
* as an address where the value of the first parameter will be copied.
*
* param arena
* param champ
*/

extern uint8_t	g_direct_jump_table_from_instr[17];

// TODO : remove libc.h
#include <libc.h>
void 			ft_vm_instr_sti(unsigned char arena[], t_dead_pool *dead_pool)
{
	int				i;
	int				reg;
	int				copy_at_address;
	unsigned char   *ptr;

	DEBUG_MODE ? ft_printf("{yellow:sti}\n") : 0;
	i = 1;
	copy_at_address = 0;
	/* Set a pointer at the beginning of the arguments */
	ptr = dead_pool->i_champ->pc + 2;
	reg = *ptr;
	if (!IS_REG(reg))
	{
		dead_pool->i_champ->pc += 1;
		dead_pool->i_champ->next_cycle += 1;
		return ;
	}
	ptr += dead_pool->i_champ->instr.arg_jump[0];
	/* Read arguments */
	while (i < dead_pool->i_champ->instr.op->nb_args)
	{
		if (dead_pool->i_champ->instr.op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				dead_pool->i_champ->pc += 1;
				dead_pool->i_champ->next_cycle += 1;
				return ;
			}
			copy_at_address += dead_pool->i_champ->reg[*ptr];
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_IND)
		{
			ft_printf("get data 1: %d\n", ft_instruction_get_data(2, ptr) + 1);
			copy_at_address += MOD(dead_pool->i_champ->pc + 1 - arena + ft_instruction_get_data(2, ptr));
			ft_printf("copy_at_address 1: %d\n", copy_at_address);
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_DIR)
		{
			ft_printf("get data 2: %d\n", ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr));
			copy_at_address += MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr));
			ft_printf("copy_at_address 2: %d\n", copy_at_address);
		}
		ptr += dead_pool->i_champ->instr.arg_jump[i];
		++i;
	}
	DEBUG_MODE ? ft_fprintf(2, "reg[%hhx] : %hhx\n", reg, *ptr) : 0;
	DEBUG_MODE ? ft_fprintf(2, "final copy_at_address : %d\n", copy_at_address) : 0;
	ft_vm_print_reg(dead_pool->i_champ);
	/* Store the value from the register */
	arena[MOD(copy_at_address)] = dead_pool->i_champ->reg[reg];
	/* Move the Program Counter */
	dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1] + dead_pool->i_champ->instr.arg_jump[2];
	/* Waiting time until the next instruction */
	dead_pool->i_champ->next_cycle += dead_pool->i_champ->instr.op->nb_cycles;
}
