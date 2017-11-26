/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_fail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:10:06 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/25 23:53:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void 				ft_vm_instr_fail(t_process *proc, const int carry_change)
{
	/* Move the Program Counter to the next byte */
	proc->pc += 1;
	/* Set the instruction cycle to the next one */
	proc->exec_cycle += 1;
	/* Set the carry to 1 if necessary */
	(carry_change == CARRY_CHANGE) ? (proc->carry = 1) : 0;
}
