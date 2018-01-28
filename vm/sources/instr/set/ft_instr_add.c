/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:15:45 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 16:38:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void		ft_instr_add(t_vm *vm, t_proc *proc)
{
	proc->reg[proc->instr->args[2].data] =
		proc->reg[proc->instr->args[0].data] + proc->reg[proc->instr->args[1].data];
	/* Display additional informations */
	if (DISPLAY_4)
		ft_display_add_sub(proc);
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[2].data];
}
