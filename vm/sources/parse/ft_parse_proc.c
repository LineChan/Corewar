/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 01:14:03 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/17 02:22:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include <fcntl.h>

#include "ft_printf.h"
void		ft_parse_proc(t_vm *vm, t_parse *parse)
{
	static int			max_proc = 0;
	static unsigned		current_proc = 0;

	ft_printf("parse proc\n");
	/* 4 processes have already been found */
	if (1 == max_proc)
		ft_exit("Too many processes want to fight");
	/* Processes's numbers can be chosen with the -n option. */
	/* If not, the File Descriptor is stored in a temporary array */
	if (0 == parse->next_arg)
		parse->next_arg = &parse->fd[current_proc++];
	/* Check if the extension (.cor) is valid */
	if (!(*(int *)".cor" ==
		*(int *)(*parse->av + ft_strlen(*parse->av) - 4)))
		ft_exit("Extension .cor not found");
	/* Open the file */
	if (IS_NEG((*parse->next_arg = open(*parse->av, O_RDONLY, 0666))))
		ft_exit("The file can't be read");
	++vm->nb_proc;
	if (vm->nb_proc == MAX_PLAYERS)
		max_proc = 1;
	++parse->av;
	--parse->ac;
	/* Reset parameters for the State Machine */
	parse->next_arg = 0;
	parse->state = OPT_STATE_DEFAULT;
}
