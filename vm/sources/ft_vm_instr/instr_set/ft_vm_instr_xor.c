/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_xor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:06:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/09 19:03:06 by mvillemi         ###   ########.fr       */
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

	ptr = dead_pool->i_champ->pc + 2;
	i = 0;
	DEBUG_MODE ? ft_printf("{yellow:xor}\n") : 0;
	while (i < (dead_pool->i_champ->instr.op->nb_args - 1))
	{
		if (dead_pool->i_champ->instr.op->arg_types[i] == T_REG)
		{
			ft_printf("T_REG : reg[%d]\n", (int)*ptr);
			xor[i] = dead_pool->i_champ->reg[*ptr];
			ft_printf("xor[%d] = %d\n", i, xor[i]);
		}
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_IND)
		{
			ft_printf("pc : %d\n", dead_pool->i_champ->pc - arena);
			ft_printf("T_IND : %d\n", ft_instruction_get_data(2, ptr));
			ft_printf("arena[%d] : %d\n", dead_pool->i_champ->pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD), arena[dead_pool->i_champ->pc - arena + ft_instruction_get_data(2, ptr)]);
			xor[i] = arena[dead_pool->i_champ->pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD)];
			ft_printf("xor[%d] = %d\n", i, xor[i]);
		}
		else
		{
			ft_printf("T_DIR\n");
			xor[i] = arena[ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->i_champ->instr.op->numero], ptr)];
			ft_printf("xor[%d] = %d\n", i, xor[i]);
			ft_vm_print_reg(dead_pool->i_champ);
			getchar();
		}
		ptr += dead_pool->i_champ->instr.arg_jump[i];
		++i;
	}
	DEBUG_MODE ? ft_printf("reg[%d] : xor[0] : %d xor[1] : %d ----> & %d \n", *ptr, xor[0] , xor[1], xor[0] ^ xor[1]) : 0;
	dead_pool->i_champ->reg[ft_instruction_get_data(1, ptr)] = xor[0] ^ xor[1];
	dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1] + dead_pool->i_champ->instr.arg_jump[2];
	if (DEBUG_MODE)
	{
		ft_vm_print_reg(dead_pool->i_champ);
		getchar();
	}
}
