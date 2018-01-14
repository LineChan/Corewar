/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:51:37 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:59:34 by mvillemi         ###   ########.fr       */
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
	if (LOG_OPT)
		ft_vm_log_intro(vm);
	/* Set up cycle_end_round */
	vm->cycle_to_die = CYCLE_TO_DIE;
	cycle_end_round = vm->cycle_to_die;
	//TODO : some adjusment for the option start_c
	vm->current_cycle = 1;
	/* Loop until there is no champion in the arena */
	while (vm->nb_champion > 0)
	{
		/* Round routine */
		while (vm->current_cycle <= cycle_end_round)
		{

			/* Cycle routine */
			ft_vm_arena_cycle_routine(vm);
			/* Dump memory */
			if ((vm->current_cycle == DUMP_OPT) || (vm->current_cycle == S_DUMP_OPT))
			{
				ft_vm_display_arena((void *)vm->arena[0], MEM_SIZE, 64, vm);
				if (vm->current_cycle == DUMP_OPT)
					return ;
			}
			++vm->current_cycle;
		}
		/* Round Check */
		ft_vm_arena_round_check(vm, &cycle_end_round);
		/* The battle stops if cycle_to_die is negative */
		if (IS_NEG(vm->cycle_to_die))
		{
			ft_vm_arena_cycle_routine(vm);
			++vm->current_cycle;
			ft_vm_arena_round_check(vm, &cycle_end_round);
			break ;
		}
	}
	/* Print the ouput of the game */
	ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_alive,
		vm->header[vm->last_alive - 1].prog_name);
}
