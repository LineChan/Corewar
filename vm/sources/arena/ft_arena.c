/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:37:36 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/31 13:48:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void		ft_arena(t_vm *vm)
{
	int			limit;
	int			round_limit;

	/* Setup the arena before the battle starts */
	ft_arena_setup(vm, &limit, &round_limit);
	if (DISPLAY_32)
		ft_visual_start(vm);
	/* Loop until there is no process left in the arena */
	while (vm->nb_proc > 0)
	{
		++limit;
		/* Cycle routine */
		if (ft_arena_cycle_routine(vm) == EXIT_FAILURE)
			return ;
		/* Round check */
		if (vm->cycle_to_die <= limit)
		{
			ft_arena_round_check(vm);
			/* -round-limit -N option */
			if (ROUND_LIMIT_OPT && (--round_limit == 0))
				break ;
			limit = 0;
		}
		/* Refresh window */
		if (DISPLAY_32)
			ft_visual_refresh(&vm->visual, vm);
	}
	/* Print the output of the game */
	ft_display_winner(vm);
}
