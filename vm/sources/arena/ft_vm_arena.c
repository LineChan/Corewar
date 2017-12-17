/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:51:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/17 14:15:12 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "ft_instruction.h"

//TODO:Libraries
#include <libc.h>
#include "ft_printf.h"

void			ft_vm_arena(t_vm *vm)
{
	int			cycle_end_round;

	/* Place champions on the arena at the right position and set them up */
	ft_vm_arena_upload(vm);
	/* Write in the log file */
	LOG_OPT ? ft_vm_log_intro(vm): 0;
	/* Set up cycle_end_round */
	vm->cycle_to_die = CYCLE_TO_DIE;
	cycle_end_round = vm->cycle_to_die;
	//TODO : some adjusment for the option start_c
	vm->current_cycle = 1;
	/* Loop until there is no champion in the arena */
	while ((vm->nb_champion > 0) && (!IS_NEG(vm->cycle_to_die)))
	{
		while (vm->current_cycle <= cycle_end_round)
		{

			DISPLAY_2 ? ft_printf("It is now cycle %d\n", vm->current_cycle) : 0;
			ft_vm_arena_cycle_routine(vm);
			/* Dump memory */
			if ((vm->current_cycle == DUMP_OPT) || (vm->current_cycle == S_DUMP_OPT))
			{
				ft_vm_print_arena((void *)vm->arena[0], MEM_SIZE, 64, vm);
				if (vm->current_cycle == DUMP_OPT)
					return ;
			}
			++vm->current_cycle;
			}
		ft_vm_arena_round_check(vm, &cycle_end_round);
	}
	#if 0
	if (DISPLAY_8)
		ft_vm_display_death(vm);
		#endif
	ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_alive,
		vm->header[vm->last_alive - 1].prog_name);
}
