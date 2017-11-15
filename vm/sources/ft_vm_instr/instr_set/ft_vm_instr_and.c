/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 23:29:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/15 17:25:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentation
//TODO : carry
/*
* brief      		Execute and :Apply an & (bit-to-bit AND) over the first
* two arguments and store the result in a registry, which is the third argument. It will change the carry
*
* param arena		Memory allocated to the Virtual Machine
* param champ
*/

//TODO : remove libc.h
#include <libc.h>
extern uint8_t	g_direct_jump_table_from_instr[17];

void			ft_vm_instr_and(unsigned char arena[], t_dead_pool *dead_pool)
{
	int				i;
unsigned int	and[2];
unsigned char	*ptr;

/* Set up a pointer at the beginning of the arguments */
ptr = dead_pool->i_champ->pc + 2;
i = 0;
DEBUG_MODE ? ft_fprintf(2, "{yellow:and}\n") : 0;
/* Read arguments */
while (i < (dead_pool->i_champ->instr.op->nb_args - 1))
{
	if (dead_pool->i_champ->instr.op->arg_types[i] == T_REG)
	{
		if (!IS_REG(*ptr))
		{
			dead_pool->i_champ->pc += 1;
			return ;
		}
		and[i] = dead_pool->i_champ->reg[*ptr];
		if (DEBUG_MODE)
		{
			ft_fprintf(2, "T_REG : reg[%d]\n", (int)*ptr);
			ft_fprintf(2, "and[%d] = %d\n", i, and[i]);
			ft_vm_print_reg(dead_pool->i_champ);
		}
	}
	else if (dead_pool->i_champ->instr.op->arg_types[i] == T_IND)
	{
		and[i] = arena[MOD(dead_pool->i_champ->pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD))];
		if (DEBUG_MODE)
		{
			ft_fprintf(2, "T_IND : %d\n", ft_instruction_get_data(2, ptr));
			ft_fprintf(2, "arena[%d] : %d\n", MOD(dead_pool->i_champ->pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD)), arena[dead_pool->i_champ->pc - arena + (ft_instruction_get_data(2, ptr) & IDX_MOD)]);
			ft_vm_print_reg(dead_pool->i_champ);
		}
	}
	else
	{
		and[i] = arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr))];
		if (DEBUG_MODE)
		{
			ft_fprintf(2, "T_DIR\n");
			ft_fprintf(2, "and[%d] = %d\n", i, and[i]);
			ft_vm_print_reg(dead_pool->i_champ);
		}
	}
	ptr += dead_pool->i_champ->instr.arg_jump[i];
	++i;
}
DEBUG_MODE ? ft_fprintf(2, "reg[%d] : and[0] : %d and[1] : %d ----> & %d \n", *ptr, and[0] , and[1], and[0] & and[1]) : 0;
/* Add argument and store the result in an register */
if (IS_REG(*ptr))
{
	dead_pool->i_champ->reg[*ptr] = and[0] & and[1];
	/* Move the Program Counter */
	dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1] + dead_pool->i_champ->instr.arg_jump[2];
}
else
	dead_pool->i_champ->pc += 1;

if (DEBUG_MODE)
{
	ft_vm_print_reg(dead_pool->i_champ);
	getchar();
}
	#if 0
	int				i;
	unsigned int	and[2];
	unsigned char	*ptr;

	/* Set up a pointer at the beginning of the arguments */
	ptr = dead_pool->champ[CHAMP_IDX].pc + 2;
	i = 0;
	DEBUG_MODE ? ft_printf("{yellow:and}\n") : 0;
	/* Read arguments */
	while (i < (dead_pool->champ[CHAMP_IDX].instr.op->nb_args - 1))
	{
		if (dead_pool->champ[CHAMP_IDX].instr.op->arg_types[i] == T_REG)
		{
			/* Check if it is a valid register number */
			if (!IS_REG(*ptr))
			{
				dead_pool->champ[CHAMP_IDX].pc += 1;
				return ;
			}
			and[i] = dead_pool->champ[CHAMP_IDX].reg[*ptr];
			if (DEBUG_MODE)
			{
				ft_printf("T_REG : reg[%d]\n", (int)*ptr);
				ft_printf("and[%d] = %d\n", i, and[i]);
				ft_vm_print_reg(&dead_pool->champ[CHAMP_IDX]);
			}
		}
		else if (dead_pool->champ[CHAMP_IDX].instr.op->arg_types[i] == T_IND)
		{
			and[i] = arena[MOD(dead_pool->champ[CHAMP_IDX].pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD))];
			if (DEBUG_MODE)
			{
				ft_printf("T_IND : %d\n", ft_instruction_get_data(2, ptr));
				ft_printf("arena[%d] : %d\n", MOD(dead_pool->champ[CHAMP_IDX].pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD)), arena[dead_pool->champ[CHAMP_IDX].pc - arena + (ft_instruction_get_data(2, ptr) & IDX_MOD)]);
				ft_vm_print_reg(&dead_pool->champ[CHAMP_IDX]);
			}
		}
		else
		{
			and[i] = arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->champ[CHAMP_IDX].instr.op->numero], ptr))];
			if (DEBUG_MODE)
			{
				ft_printf("T_DIR\n");
				ft_printf("and[%d] = %d\n", i, and[i]);
				ft_vm_print_reg(&dead_pool->champ[CHAMP_IDX]);
			}
		}
		ptr += dead_pool->champ[CHAMP_IDX].instr.arg_jump[i];
		++i;
	}
	DEBUG_MODE ? ft_printf("reg[%d] : and[0] : %d and[1] : %d ----> & %d \n", *ptr, and[0] , and[1], and[0] & and[1]) : 0;
	/* Add argument and store the result in an register */
	if (IS_REG(*ptr))
	{
		dead_pool->champ[CHAMP_IDX].reg[*ptr] = and[0] & and[1];
		/* Move the Program Counter */
		dead_pool->champ[CHAMP_IDX].pc += 2 + dead_pool->champ[CHAMP_IDX].instr.arg_jump[0] + dead_pool->champ[CHAMP_IDX].instr.arg_jump[1] + dead_pool->champ[CHAMP_IDX].instr.arg_jump[2];
	}
	else
		dead_pool->champ[CHAMP_IDX].pc += 1;

	if (DEBUG_MODE)
	{
		ft_vm_print_reg(&dead_pool->champ[CHAMP_IDX]);
		getchar();
	}
	#endif
}
