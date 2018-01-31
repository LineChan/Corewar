/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_cycle_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:51:30 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/31 15:38:44 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include <unistd.h>

int				ft_arena_cycle_routine(t_vm *vm)
{
	/* Dump if necessary and the battle stops */
	if (vm->current_cycle == DUMP_OPT)
		return (ft_display_arena(vm));
	if (vm->current_cycle == S_DUMP_OPT)
	{
		/* Display the arena, pause then continue the battle */
		ft_display_arena(vm);
		read(0, 0, 1);
	}
	/* Increase the cycle counter */
	++vm->current_cycle;
	/* Display additional informations */
	if (DISPLAY_2)
		ft_printf("It is now cycle %d\n", vm->current_cycle);
	/* The instruction routine is applied on every proces */
	ft_list_apply_data(&vm->proc_head, (void *)vm, &ft_arena_instr_routine);
	return (EXIT_SUCCESS);
}
