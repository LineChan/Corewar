/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:51:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 01:08:21 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

//TODO:Libraries
#include <libc.h>
#include "ft_printf.h"
void			ft_vm_arena(t_vm *vm, int *nb_champion)
{
	unsigned int			cycle_to_die;

	/* Place champions on the arena at the right position and set them up */
	ft_vm_arena_upload(vm, *nb_champion);
	/* Set up cycle_to_die */
	LOG_OPT ? ft_vm_log_intro (vm): 0;
	cycle_to_die = CYCLE_TO_DIE;
	//ft_vm_print_arena((void *)vm->arena, MEM_SIZE, 64, vm);
	/* Loop until there is no champion in the arena */
	//TODO : some adjusment for the option start_c
	while (*nb_champion)
	{
		while (vm->current_cycle <= cycle_to_die)
		{

			ft_vm_arena_cycle_routine(vm);
			++vm->current_cycle;
		}
		ft_vm_arena_round_check(vm, nb_champion, &cycle_to_die);
	}
}
