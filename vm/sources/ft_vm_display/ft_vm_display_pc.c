/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_pc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:49:28 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 15:52:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include <unistd.h>

void			ft_vm_display_pc(t_vm const *vm,
								t_process const *proc,
								const int size)
{
	int		i;

	i = 0;
	ft_printf("ADV %d (%#0.4x -> %#0.4x) ", size, proc->pc - vm->arena[0],
					proc->pc + size - vm->arena[0]);
	while (i != size)
	{
		ft_printf("%02hhx ", *(proc->pc + i));
		++i;
	}
	write(1, "\n", 1);
}
