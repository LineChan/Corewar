/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_new_process_kid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 00:58:40 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/15 17:58:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "ft_instruction.h"

#include "ft_printf.h"
void			ft_vm_new_process_kid(t_vm *vm,
									t_process *proc,
									const unsigned int index)
{
	t_process			*new;

	/* Allocate a new proceess */
	if (!(new = ft_memalloc(sizeof(t_process))))
		ft_exit("Failed memory allocation");
	/* Copy data from parent */
	ft_memcpy((void *)new, proc, sizeof(t_process));
	/* Change the process' reference */
	new->process_nb = --vm->current_proc_nb;
	/* Set up the Program Counter to the new location  */
	new->pc = &vm->arena[0][index];
	/* Initialize the first instruction */
	ft_vm_new_process_init_instr(new);
	/* Add the new process to the list */
	ft_list_add(&new->list, &vm->process_head);
	/* Update the champions number */
	++vm->nb_champion;
}
