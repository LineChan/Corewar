/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_round_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:47:26 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/28 22:21:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

#include "ft_printf.h"
void			ft_arena_round_check(t_vm *vm)
{
	++vm->check;
	ft_list_apply_data(&vm->proc_head, (void *)vm, &ft_proc_check);
	/* If the total number of live instruction is bigger than NBR_LIVE
		or if cycle_to_die hasn't been decreased since MAX_CHECKS round */
	if ((vm->total_live >= NBR_LIVE) || (vm->check >= MAX_CHECKS))
	{
		/* cycle_to_die is decreased of CYCLE_DELTA */
		vm->cycle_to_die -= CYCLE_DELTA;
		if (DISPLAY_2)
			ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
		/* The number of checks is reset */
		vm->check = 0;
	}
	/* The total number of live instructions is reset */
	vm->total_live = 0;
}
