/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:51:30 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/24 17:27:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_arena_setup(t_vm *vm/*, int *cycle_end_round*/, int *limit)
{
	/* Place processes at their right position */
	ft_arena_upload(vm);
	/* Setup parameters before the battle */
	vm->cycle_to_die = CYCLE_TO_DIE;
	if (0 == DUMP_OPT)
		DUMP_OPT = -1;
	//*cycle_end_round = CYCLE_TO_DIE;
	*limit = 0;
	vm->current_cycle = 0;
}
