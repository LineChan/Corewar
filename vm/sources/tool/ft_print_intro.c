/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_intro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:33:16 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 00:55:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_curse.h"

void			ft_print_intro(t_vm const *vm)
{
	int			i;

	i = 0;
	/* Print a small presentation of each process */
	if (DISPLAY_32)
	{
		ft_printf("COUCOU INTRO\n");
		//ft_curse_intro();
		return ;
	}
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
