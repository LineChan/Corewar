/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:21:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/11 00:50:37 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void 			ft_vm_read_header(t_vm *vm)
{
	int			i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (vm->fd[i])
		{
			ft_vm_read_header_magic(vm, i);
			ft_vm_read_header_name(vm, i);
			ft_vm_read_header_size(vm, i);
			ft_vm_read_header_comment(vm, i);
		}
		++i;
	}
}
