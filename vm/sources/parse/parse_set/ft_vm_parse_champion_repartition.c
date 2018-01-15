/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_champion_repartition.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 00:17:31 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/15 17:43:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void 	ft_vm_parse_champion_repartition(t_vm *vm)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	/* Champions with no specific number are inserted at empty spots in the */
	/* champions' array */
	while (i < MAX_PLAYERS)
	{
		/* Check if a File Descriptor has been opened */
		while (vm->fd[j])
			++j;
		vm->fd[j] = vm->fd_tmp[i];
		++i;
	}
	#if 0
	/* If no process execute the live instruction during the 1st round, */
	/* the last one parsed wins */
	vm->last_alive = i;
	/* Save the lastest champion's number as a reference for new processes */
	vm->current_proc_nb = -i;
	#endif
}
