/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_intro.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 23:00:42 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/27 17:31:37 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_intro(t_vm *vm)
{
	int			i;

	ft_log("# ----------------  NEW EPIC BATTLE ----------------\n");
	/* Write the name of the all the champions */
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (vm->fd[i])
		ft_log("# Player %d: %s\n", i + 1, vm->header[i].prog_name);
		++i;
	}
	ft_log("# Starting cycle : %d\n", vm->current_cycle);
	ft_log("# --------------------------------------------------\n");
}
