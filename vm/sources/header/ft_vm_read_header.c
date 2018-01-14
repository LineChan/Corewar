/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:21:33 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:30:42 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void 			ft_vm_read_header(t_vm *vm)
{
	int			i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		/* Apply routine to each process */
		if (vm->fd[i])
		{
			/* Check if the Magic Number is valid */
			ft_vm_read_header_magic(vm, i);
			/* Read the process' name */
			ft_vm_read_header_name(vm, i);
			/* Read the process' size */
			ft_vm_read_header_size(vm, i);
			/* Read the process' comment */
			ft_vm_read_header_comment(vm, i);
		}
		++i;
	}
}
