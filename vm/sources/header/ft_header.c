/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:48:39 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/17 17:45:21 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

#include "ft_printf.h"
void			ft_header(t_vm *vm)
{
	int			i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		/* Apply routine to each process */
		if (vm->fd[i])
		{
			/* Check if the Magic Number is valid */
			ft_header_magic(vm, i);
			/* Read the process' name */
			ft_header_name(vm, i);
			/* Read the process' size */
			ft_header_size(vm, i);
			/* Read the process' comment */
			ft_header_comment(vm, i);
		}
		++i;
	}
}
