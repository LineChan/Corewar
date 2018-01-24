/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:37:36 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/24 17:14:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void		ft_arena(t_vm *vm)
{
	//int			cycle_end_round;
	int			limit;

	ft_arena_setup(vm/*, &cycle_end_round*/, &limit);
	/* Loop until there is no process left in the arena */
	while (vm->nb_proc > 0)
	{
		++limit;
		/* Cycle routine */
		if (ft_arena_cycle_routine(vm) == EXIT_FAILURE)
			return ;
		/* Round check */
		//if (cycle_end_round <= limit)
		if (vm->cycle_to_die <= limit)
		{
			ft_arena_round_check(vm/*, &cycle_end_round*/);
			limit = 0;
		}
	}
	/* Print the output of the game */
	ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_alive,
		vm->header[vm->last_alive - 1].prog_name);
}
#if 0
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
		if (IS_NEG(vm->cycle_to_die))
		{
			ft_arena_cycle_routine(vm);
			++vm->current_cycle;
			ft_arena_round_check(vm, &cycle_end_round);
			break ;
		}
		#endif
	#if 0
	#endif
