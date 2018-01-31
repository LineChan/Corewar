/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_proc_kid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:15:34 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/31 13:48:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "ft_instruction.h"

void		ft_new_proc_kid(t_vm *vm, t_proc *proc, unsigned int const index)
{
	t_proc		*new;

	/* -proc-limit option */
	if (vm->nb_proc == PROC_LIMIT_OPT)
		return ;
	/* Allocate a new process */
	if (!(new = ft_memalloc(sizeof(t_proc)))
		|| !(new->instr = ft_memalloc(sizeof(t_instr))))
		ft_exit("Failed memory allocation");
	/* Copy data from parent */
	ft_memcpy((void *)new, proc, sizeof(t_proc));
	/* Change the process' reference */
	new->proc_nb = --vm->current_proc_nb;
	/* Set up the Program Counter to the new location */
	new->pc = index;
	/* Initialize the 1st instruction */
	new->next_op = 0;
	/* Update the visual */
	vm->visual.board.pc_position[index] = proc->parent_nb;
	/* Add the new process to the list */
	ft_list_add(&new->list, &vm->proc_head);
	/* Update the number of processes */
	++vm->nb_proc;
}
