/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_read_instruction.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:11:11 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/24 23:55:07 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

extern uint8_t	g_direct_jump_table_from_instr[17];

void			ft_vm_arena_read_instruction(char *arena)
{
	extern t_op	g_op_tab[17];

	ft_vm_arena_print((void *)arena, MEM_SIZE, 64);
	ft_fprintf(2, "champion1 : %02hhx\n", *PC->champion1);
	ft_printf("op1 : %s\n", g_op_tab[(int)*PC->champion1].name);
	ft_printf("carry1 : %d\n", PC->carry1);
	PC->carry1 = 1;
	ft_printf("{yellow:carry1} : %d\n", PC->carry1);
	ft_printf("op2 : %s\n", g_op_tab[(int)*PC->champion2].name);
	ft_printf("op3 : %s\n", g_op_tab[(int)*PC->champion3].name);
	ft_printf("op4 : %s\n", g_op_tab[(int)*PC->champion4].name);
}
