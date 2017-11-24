/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:51:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/24 18:02:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

#include "ft_printf.h"
void			ft_vm_arena(t_vm *vm, int *nb_champion)
{
	(void)nb_champion;
	ft_memset((void *)vm->arena, 0, MEM_SIZE * 2);
	/* Place champions on the arena at the right position and set them up */
	ft_vm_arena_upload(vm, *nb_champion);
	/* Set up cycle_to_die */
	vm->cycle_to_die = CYCLE_TO_DIE;
	while (*nb_champion)
	{

	}
}
