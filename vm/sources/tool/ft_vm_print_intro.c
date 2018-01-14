/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_print_intro.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:00:47 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:37:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void 			ft_vm_print_intro(t_vm const *vm)
{
	int			i;

	i = 0;
	/* Print a small presentation of each process */
	ft_printf("Introducing contestants...\n");
	while (i < MAX_PLAYERS)
	{
		/* Apply routine to each opened process */
		if (vm->fd[i])
		{
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				i + 1,
				vm->header[i].prog_size,
				vm->header[i].prog_name,
				vm->header[i].comment);
			}
		++i;
	}
}
