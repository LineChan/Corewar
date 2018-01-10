/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_upload.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:59:07 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/08 21:54:18 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "macro.h"
#include "ft_printf.h"
#include "ft_instruction.h"
#include <unistd.h>

//TODO : libs
#include "ft_printf.h"
void			ft_vm_arena_upload(t_vm *vm)
{
	int			step;
	int			index;
	int			i;

	/* Find the distance between 2 champions */
	step = MEM_SIZE / vm->nb_champion;
	index = 0;
	i = 0;
	while (i < MAX_PLAYERS)
	{
		/* If the champion's File Descriptor is open */
		if (vm->fd[i])
		{
			/* Set up the starting position in the arena */
			vm->index[i] = index;
			/* Copy the champion in the arena */
			if (IS_NEG(read(vm->fd[i], &vm->arena[0][index], vm->header[i].prog_size)))
				ft_exit("Can't upload champions in the arena");
			/* Create a new process */
			ft_vm_new_process(vm, i + 1, -i - 1, index);
			/* Close the champion's File Descriptor */
			close(vm->fd[i]);
			/* Move the starting point for the next champion */
			index += step;
		}
		++i;
	}
}