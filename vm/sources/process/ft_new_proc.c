/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:50:08 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 20:58:13 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_string.h"

void				ft_new_proc(t_vm *vm, const int ref, const int index)
{
	t_proc		*new;

	/* Allocate a new process */
	if (!(new = ft_memalloc(sizeof(t_proc))))
		ft_exit("Memory allocation failed");
	if (!(new->instr = ft_memalloc(sizeof(t_instr))))
		ft_exit("Memory allocation failed");
	/* Reference to the champion who created the process */
	new->parent_nb = ref + 1;
	/* Process reference */
	new->proc_nb = - (ref + 1);
	/* Put the process' numer in the 1st register */
	new->reg[1] = new->proc_nb;
	/* Setup the Program Counter */
	new->pc = index;
	/* Add the process to the list */
	ft_list_add(&new->list, &vm->proc_head);
}
