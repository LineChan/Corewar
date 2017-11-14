/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_xor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:06:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 23:39:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentaiton
//TODO : carry

/*
* brief      		Execute xor :Apply an ^ (bit-to-bit XOR) over the first
* two arguments and store the result in a registry, which is the third argument.
* It will change the carry.
*
* param arena
* param champ
*/
//TODO : remove libc.h

#include <libc.h>
extern uint8_t	g_direct_jump_table_from_instr[17];

void			ft_vm_instr_xor(unsigned char arena[], t_dead_pool *dead_pool)
{
	int				i;
	unsigned int	xor[2];
	unsigned char	*ptr;

	/* Set a pointer at the beginning of the arguments */
	ptr = dead_pool->champ[CHAMP_IDX].pc + 2;
	i = 0;
	DEBUG_MODE ? ft_printf("{yellow:xor}\n") : 0;
	/* Read arguments */
	while (i < (dead_pool->champ[CHAMP_IDX].instr.op->nb_args - 1))
	{
		if (dead_pool->champ[CHAMP_IDX].instr.op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				dead_pool->champ[CHAMP_IDX].pc += 1;
				return ;
			}
			xor[i] = dead_pool->champ[CHAMP_IDX].reg[*ptr];
			if (DEBUG_MODE)
			{

				ft_printf("T_REG : reg[%d]\n", (int)*ptr);
				ft_printf("xor[%d] = %d\n", i, xor[i]);
			}
		}
		else if (dead_pool->champ[CHAMP_IDX].instr.op->arg_types[i] == T_IND)
		{
			xor[i] = arena[MOD(dead_pool->champ[CHAMP_IDX].pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD))];
			if (DEBUG_MODE)
			{
				ft_printf("pc : %d\n", dead_pool->champ[CHAMP_IDX].pc - arena);
				ft_printf("T_IND : %d\n", ft_instruction_get_data(2, ptr));
				ft_printf("arena[%d] : %d\n", dead_pool->champ[CHAMP_IDX].pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD), arena[dead_pool->champ[CHAMP_IDX].pc - arena + ft_instruction_get_data(2, ptr)]);
				ft_printf("xor[%d] = %d\n", i, xor[i]);
			}
		}
		else
		{
			xor[i] = arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->champ[CHAMP_IDX].instr.op->numero], ptr))];
			if (DEBUG_MODE)
			{
				ft_printf("T_DIR\n");
				ft_printf("xor[%d] = %d\n", i, xor[i]);
				ft_vm_print_reg(&dead_pool->champ[CHAMP_IDX]);
			}
		}
		ptr += dead_pool->champ[CHAMP_IDX].instr.arg_jump[i];
		++i;
	}
	DEBUG_MODE ? ft_fprintf(2,"reg[%d] : xor[0] : %d xor[1] : %d ----> & %d \n", *ptr, xor[0] , xor[1], xor[0] ^ xor[1]) : 0;
	/* Compute the result and save it in a register */
	if (IS_REG(*ptr))
	{
		dead_pool->champ[CHAMP_IDX].reg[*ptr] = xor[0] ^ xor[1];
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
}
