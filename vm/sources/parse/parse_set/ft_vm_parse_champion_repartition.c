/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_champion_repartition.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 00:17:31 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/21 18:03:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

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
		while (vm->fd[j])
			++j;
		vm->fd[j] = vm->fd_tmp[i];
		++i;
	}
	vm->last_alive = j;
	vm->current_proc_nb = -j;
}
