/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:51:30 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 16:50:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_arena_setup(t_vm *vm, int *limit)
{
	/* Place processes at their right position */
	ft_arena_upload(vm);
	/* Setup parameters before the battle */
	vm->cycle_to_die = CYCLE_TO_DIE;
	if (0 == DUMP_OPT)
		DUMP_OPT = -1;
	*limit = 0;
}
