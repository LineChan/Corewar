/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_process_init_instr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 18:13:14 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 15:40:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_string.h"

void		ft_vm_new_process_init_instr(t_process *new)
{
	extern t_op			g_op_tab[17];

	/* If the op number is valid, the 1st instruction starts after its sleep time */
	if (OPCODE_IS_VALID(*new->pc))
		new->exec_cycle += g_op_tab[*new->pc].nb_cycles;
	/* Otherwise it starts at the next cycle */
	else
		new->exec_cycle += 1;
	/* Initialize next_op */
	new->next_op = *new->pc;
	/* Create a new_process */
	if (!(new->instr = ft_memalloc(sizeof(t_instr))))
		ft_exit("Error : failed memory allocation");
}
