/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_sti.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:51:53 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 12:52:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_instruction.h"

void			ft_vm_display_sti(t_vm *vm, t_process const *proc)
{
	ft_printf("P %4d | sti r%d %d %d\n",
				-proc->process_nb,
				proc->instr->args[0].data,
				proc->instr->args[1].data,
				proc->instr->args[2].data);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
				proc->instr->args[1].data,
				proc->instr->args[2].data,
				proc->instr->args[1].data + proc->instr->args[2].data,
				proc->pc - vm->arena[0] +
				(proc->instr->args[1].data + proc->instr->args[2].data) % IDX_MOD);
}
