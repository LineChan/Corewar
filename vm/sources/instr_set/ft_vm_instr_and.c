/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 23:29:24 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/07 17:49:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentation
//TODO : carry
/*
* brief      		Execute and :Apply an & (bit-to-bit AND) over the first
* two arguments and store the result in a registry, which is the third argument. It will change the carry
*
* param arena
* param champ
*/

//TODO : remove libc.h
#include <libc.h>
extern uint8_t	g_direct_jump_table_from_instr[17];

void			ft_vm_instr_and(unsigned char arena[],
								t_dead_pool *dead_pool,
								t_champion *champ)
{
	int				i;
	unsigned int	and[2];
	unsigned char	*ptr;

	(void)dead_pool;
	ptr = champ->pc + 2;
	i = 0;
	DEBUG_MODE ? ft_printf("{yellow:and}\n") : 0;
	if (DEBUG_MODE)
	{
		ft_vm_print_reg(champ);
		getchar();
	}
	while (i < (champ->instr.op->nb_args - 1))
	{
		if (champ->instr.op->arg_types[i] == T_REG)
		{
			ft_printf("T_REG : reg[%d]\n", (int)*ptr);
			and[i] = champ->reg[*ptr];
			ft_printf("and[%d] = %d\n", i, and[i]);
			ft_vm_print_reg(champ);
			getchar();
		}
		else if (champ->instr.op->arg_types[i] == T_IND)
		{
			ft_printf("pc : %d\n", champ->pc - arena);
			ft_printf("T_IND : %d\n", ft_instruction_get_data(2, ptr));
			ft_printf("arena[%d] : %d\n", champ->pc - arena + ft_instruction_get_data(2, ptr), arena[champ->pc - arena + ft_instruction_get_data(2, ptr)]);



			and[i] = arena[MOD(champ->pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD))];




			ft_printf("and[%d] = %d\n", i, and[i]);
			ft_vm_print_reg(champ);
			getchar();
		}
		else
		{
			ft_printf("T_DIR\n");
			and[i] = arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[champ->instr.op->numero], ptr))];
			ft_printf("and[%d] = %d\n", i, and[i]);
			ft_vm_print_reg(champ);
			getchar();
		}
		ptr += champ->instr.arg_jump[i];
		++i;
	}
	DEBUG_MODE ? ft_printf("reg[%d] : and[0] : %d and[1] : %d ----> & %d \n", *ptr, and[0] , and[1], and[0] & and[1]) : 0;
	champ->reg[ft_instruction_get_data(1, ptr)] = and[0] & and[1];
	champ->pc += 2 + champ->instr.arg_jump[0] + champ->instr.arg_jump[1] + champ->instr.arg_jump[2];
	if (DEBUG_MODE)
	{
		ft_vm_print_reg(champ);
		getchar();
	}
}
