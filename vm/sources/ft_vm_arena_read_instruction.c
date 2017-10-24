/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_read_instruction.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:11:11 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/24 19:18:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

void			ft_vm_arena_read_instruction(char *arena)
{
	ft_vm_arena_print((void *)arena, MEM_SIZE, 64);
	ft_vm_arena_print_pc();
	ft_printf("op1 : %s\n", g_op_tab[0][1]);
}
