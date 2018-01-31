/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:51:30 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 17:17:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_arena_setup(t_vm *vm, int *limit, int *round_limit)
{
	/* Place processes at their right position */
	ft_arena_upload(vm);
	/* Setup parameters before the battle */
	vm->cycle_to_die = CYCLE_TO_DIE;
	/* -dump N */
	if (0 == DUMP_OPT)
		DUMP_OPT = -1;
	/* -start-cycle N */
	if (vm->current_cycle)
		--vm->current_cycle;
	if (0 == S_DUMP_OPT)
		S_DUMP_OPT = -1;
	*limit = 0;
	*round_limit = ROUND_LIMIT_OPT;
}
