/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_new_process_kid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 00:58:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 15:23:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
// TODO : REMOVE EXIT FAIL AND DO A REAL EXIT FUNC
#include "ft_printf.h"
#include "macro.h"

void			ft_vm_new_process_kid(t_vm *vm,
									t_process *proc,
									const unsigned int index)
{
	extern t_op			g_op_tab[17];
	t_process			*new;
	static int			current_proc_nb = -5;

	/* Allocate a new proceess */
	ASSERT(!(new = ft_memalloc(sizeof(t_process))));
	/* Copy data from parent */
	ft_memcpy((void *)new, proc, sizeof(t_process));
	(void)proc;
	/* Change the process' reference */
	new->process_nb = current_proc_nb--;
	/* Set up the Program Counter to the new location  */
	new->pc = &vm->arena[0][index];
	/* Update the execution cycle */
	if (IS_INSTR(*new->pc))
		new->exec_cycle += g_op_tab[*new->pc].nb_cycles;
	else
		new->exec_cycle += 1;
	/* Add the new process to the list */
	ft_list_add(&new->list, &vm->process_head);
	/* Update the champions number */
	vm->nb_champion += 1;
}
