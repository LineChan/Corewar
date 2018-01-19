/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:37:36 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 16:47:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_arena(t_vm *vm)
{
	int			cycle_end_round;

	/* Place processes at their right position */
	ft_arena_upload(vm);
	/* Setup parameter before the battle */
	vm->cycle_to_die = CYCLE_TO_DIE;
	cycle_end_round = CYCLE_TO_DIE;
	vm->current_cycle = 1;
	/* Loop until there is no process in the arena */
	while (vm->nb_proc > 0)
	{
		/* Round routine */
		while (vm->current_cycle <= cycle_end_round)
		{
			/* Cycle routine */
			ft_arena_cycle_routine(vm);
			if (vm->current_cycle == DUMP_OPT)
			{
				ft_display_arena((void *)vm->arena[0], MEM_SIZE, 64, vm);
				return ;
			}
			++vm->current_cycle;
		}
		/* Round Check */
		ft_arena_round_check(vm, &cycle_end_round);
	}
	#if 0
	#endif
}
