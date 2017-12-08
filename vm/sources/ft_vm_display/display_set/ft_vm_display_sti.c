/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_sti.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:51:53 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/08 01:33:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_vm_display_sti(t_vm *vm, t_process *proc,
										const int address[2])
{
	ft_printf("P    %d | sti r%d %d %d\n", proc->parent_nb, *(proc->pc + 2), address[0] % MEM_SIZE, address[1] % MEM_SIZE);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
					address[0] % MEM_SIZE, address[1] % MEM_SIZE, (address[0] + address[1]) % MEM_SIZE,
					proc->pc - vm->arena[0] + (address[0] + address[1]) % IDX_MOD);
}
