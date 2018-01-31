/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_upload.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:39:58 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 22:10:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_visual.h"
#include "ft_string.h"
#include <unistd.h>

void			ft_arena_upload(t_vm *vm)
{
	int			step;
	int			index;
	int			i;

	i = 0;
	index = 0;
	step = MEM_SIZE / vm->nb_proc;
	while (i < MAX_PLAYERS)
	{
		if (vm->fd[i])
		{
			/* Create a new process */
			ft_new_proc(vm, i, index);
			/* Copy the process in the arena */
			if (IS_NEG(read(vm->fd[i], &vm->arena[index], vm->header[i].prog_size)))
				ft_exit("Can't upload process in the arena");
			if (DISPLAY_32)
			{
				/* fill color */
				//ft_memset(&vm->visual[index], i + 1, vm->header[i].prog_size/*ch->header.prog_size*/);
				ft_memset(vm->visual.board.color + index, i + 1, vm->header[i].prog_size);
				vm->visual.board.pc_position[index] = i + 1;
				//vm->visual.board.pc_position[index] = i + 1;
				#if 0
				ft_curse_assign_cell(vm, index, vm->header[i].prog_size, i + 1);
				vm->curse->grid[index] = i + 1 + MAX_PLAYERS;
				#endif
			}
			/* Initialize the 1st instruction */
			C_PROCESS(vm->proc_head.next)->next_op = vm->arena[index];
			ft_instr_update_exec_cycle(C_PROCESS(vm->proc_head.next));
			/* Close the process File Descriptor */
			close(vm->fd[i]);
			/* Move the starting point for the next process */
			index += step;
		}
		++i;
	}
	/* If no process executes the live instruction during the 1st round,
		the last one parsed wins */
	vm->current_proc_nb = C_PROCESS(vm->proc_head.next)->proc_nb;
	/* Save the latest process' number as a reference for new processes */
	vm->last_alive = -vm->current_proc_nb;
}
