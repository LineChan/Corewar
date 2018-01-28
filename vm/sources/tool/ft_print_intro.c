/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_intro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:33:16 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/28 22:59:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_visual.h"
#include "ft_printf.h"

void			ft_print_intro(t_vm *vm)
{
	int			i;

	i = 0;
	/* Print a small presentation of each process */
	ft_printf("Introducing contestants...\n");
	while (i < MAX_PLAYERS)
	{
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
