/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_print_intro.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:00:47 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/30 17:26:42 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void 			ft_vm_print_intro(t_vm *vm)
{
	int			i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < MAX_PLAYERS)
	{
		if (vm->fd[i])
		{
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				i + 1, vm->header[i].prog_size, vm->header[i].prog_name,
				vm->header[i].comment);
			}
		++i;
	}
}
