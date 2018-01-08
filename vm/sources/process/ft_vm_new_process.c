/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_new_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:34:55 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/06 18:17:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "ft_instruction.h"

void 			ft_vm_new_process(t_vm *vm,
									const int parent_nb,
									const int process_nb,
									const unsigned int index)
{
	t_process			*new;

	/* Allocate a new process */
	if (!(new = ft_memalloc(sizeof(t_process))))
		ft_exit("Memory allocation failed");
	/* Reference to the champion who created the process */
	new->parent_nb = parent_nb;
	/* Process reference */
	new->process_nb = process_nb;
	/* Put the champion's number in the 2st register */
	new->reg[1] = process_nb;
	/* Set up the Program Counter */
	new->pc = &vm->arena[0][index];
	/* Initialize the first instruction */
	ft_vm_new_process_init_instr(vm, new);
	/* Add the process to the list */
	ft_list_add(&new->list, &vm->process_head);
}
