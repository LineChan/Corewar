/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_upload.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:59:07 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 14:42:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "macro.h"
#include "ft_printf.h"
#include <unistd.h>

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
			ASSERT(IS_NEG(read(vm->fd[i], &vm->arena[0][index], vm->header[i].prog_size)));
			#if 0
			if
				EXIT_FAIL("Error : Failed read");
				#endif
			/* Create a new process */
			ft_vm_new_process(vm, i + 1, -i - 1, index);
			/* Put the champion's number in the 1st register */
			C_PROCESS(vm->process_head.next)->reg[1] = -i - 1;
			/* Close the champion's File Descriptor */
			close(vm->fd[i]);
			/* Move the starting point for the next champion */
			index += step;
		}
		++i;
	}
}
