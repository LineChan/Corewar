/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_ldi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 21:26:34 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/07 23:28:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_vm_display_ldi(t_vm *vm, t_process *proc, const int tab[2],
									const unsigned char *ptr)
{
	ft_printf("P    %d | ldi %d %d r%d\n", proc->parent_nb, tab[0], tab[1], *ptr);
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
					tab[0], tab[1], tab[0] + tab[1],
					proc->pc - vm->arena[0] + (tab[0] + tab[1]) % IDX_MOD);
}
