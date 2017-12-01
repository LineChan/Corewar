/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:51:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/01 10:31:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

//TODO:Libraries
#include <libc.h>
#include "ft_printf.h"
void			ft_vm_arena(t_vm *vm)
{
	unsigned int			cycle_end_round;
	unsigned int			cycle_to_die;

	/* Place champions on the arena at the right position and set them up */
	ft_vm_arena_upload(vm);
	/* Set up cycle_end_round */
	LOG_OPT ? ft_vm_log_intro(vm): 0;
	cycle_to_die = CYCLE_TO_DIE;
	cycle_end_round = cycle_to_die;
	//ft_vm_print_arena((void *)vm->arena, MEM_SIZE, 64, vm);
	/* Loop until there is no champion in the arena */
	//TODO : some adjusment for the option start_c
	vm->current_cycle = 1;
	while (vm->nb_champion > 0)
	{
		while (vm->current_cycle <= cycle_end_round)
		{

			DISPLAY_2 ? ft_printf("It is now cycle %d\n", vm->current_cycle) : 0;
			ft_vm_arena_cycle_routine(vm);
			if (vm->current_cycle == DUMP_OPT)
			{
				ft_vm_print_arena((void *)vm->arena[0], MEM_SIZE, 64, vm);
				return ;
			}
			++vm->current_cycle;
		}
		ft_vm_arena_round_check(vm, &cycle_end_round, &cycle_to_die);
		getchar();
	}
	if (vm->last_alive)
	{
		ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_alive,
			vm->header[vm->last_alive - 1].prog_name);
	}
	else
		ft_printf("{red:Nobody} won the battle !\n");
}
