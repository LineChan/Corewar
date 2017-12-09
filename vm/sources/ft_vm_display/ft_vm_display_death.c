/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_death.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:01:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 15:50:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_vm_display_death(t_vm const *vm)
{
	int			i;

	i = MAX_PLAYERS;
	while (i)
	{
		if (vm->fd[i - 1])
		{
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				i, vm->current_cycle - vm->option.death[i - 1] - 1, vm->cycle_to_die);
		}
		--i;
	}
}
