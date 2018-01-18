/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_upload.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:39:58 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 18:12:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <unistd.h>

#include "ft_printf.h"
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
			if (IS_NEG(read(vm->fd[i], &vm->arena[0][index], vm->header[i].prog_size)))
				ft_exit("Can't upload process in the arena");
			/* Initialize the 1st instruction */
			C_PROCESS(vm->proc_head.next)->next_op = vm->arena[0][index];
			ft_instr_update_exec_cycle(vm, C_PROCESS(vm->proc_head.next));
			/* Close the process File Descriptor */
			close(vm->fd[i]);
			/* Move the starting point for the next process */
			index += step;
		}
		++i;
	}
	/* If no process executes the live instruction during the 1st round, */
	/* the last one parsed wins */
	vm->current_proc_nb = C_PROCESS(vm->proc_head.next)->proc_nb;
	/* Save the latest process' number as a reference for new processes */
	vm->last_alive = -vm->current_proc_nb;
}
