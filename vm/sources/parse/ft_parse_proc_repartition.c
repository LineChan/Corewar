/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_proc_repartition.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:22:36 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/20 21:48:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_parse_proc_repartition(t_vm *vm, t_parse *parse)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	/* Processes with no specific numbers are inserted at empty spots in the
		process' array */
	while (i < MAX_PLAYERS)
	{
		/* Check if a File Descriptor has been opened */
		while (vm->fd[j])
			++j;
		vm->fd[j] = parse->fd[i];
		++j;
		++i;
	}
	/* If any process has executed the live instruction during the 1st round,
		the last one parsed wins */
	vm->last_alive = i;
	/* Save the lastest process' number as a reference for new processes */
	vm->current_proc_nb = -i;
}
