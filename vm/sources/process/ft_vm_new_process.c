/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_new_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:34:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/10 23:52:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
// TODO : REMOVE EXIT FAIL AND DO A REAL EXIT FUNC
#include "ft_printf.h"
#include "macro.h"

void 			ft_vm_new_process(t_vm *vm,
									const int parent_nb,
									const int process_nb,
									const unsigned int index)
{
	extern t_op			g_op_tab[17];
	t_process			*new;

	/* Allocate a new process */
	if (!(new = ft_memalloc(sizeof(t_process))))
		ft_exit("Memory allocation failed");
	/* Reference to the champion who created the process */
	new->parent_nb = parent_nb;
	/* Process reference */
	new->process_nb = process_nb;
	/* Set up the Program Counter */
	new->pc = &vm->arena[0][index];
	/* Initialize the process with the 1st instruction */
	new->exec_cycle = g_op_tab[*new->pc].nb_cycles;
	/* Add the process to the list */
	ft_list_add(&new->list, &vm->process_head);
}
