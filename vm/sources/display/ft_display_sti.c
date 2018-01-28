/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_sti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:43:32 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 16:08:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_display_sti(t_proc const *proc)
{
	ft_printf("P %4d | sti r%d %d %d\n",
				-proc->proc_nb,
				proc->instr->args[0].data,
				proc->instr->args[1].data,
				proc->instr->args[2].data);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
				proc->instr->args[1].data,
				proc->instr->args[2].data,
				proc->instr->args[1].data + proc->instr->args[2].data,
				proc->pc +
				(proc->instr->args[1].data + proc->instr->args[2].data) % IDX_MOD);
}
