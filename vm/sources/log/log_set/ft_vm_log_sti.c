/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_sti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:42:38 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/06 19:38:19 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_instruction.h"

void				ft_vm_log_sti(t_vm *vm, t_process const *proc)
{
	ft_log("  Cycle %-7d Process %2d --- %-5s\n",
						vm->current_cycle,
						-proc->process_nb,
						"sti");
	ft_vm_log_arg(proc->instr);
	ft_log("\t\tPC at %d + (%d + %d) %% IDX_MOD\n",
				proc->pc - vm->arena[0],
				proc->instr->args[1].data,
				proc->instr->args[2].data);
	ft_log("\t\tarena[%d %% IDX_MOD] --> reg[%d]\n",
				MOD(proc->pc - vm->arena[0] + (proc->instr->args[1].data + proc->instr->args[2].data) % IDX_MOD),
				proc->instr->args[0].data);
	ft_log("\t\t------------------------------- %4d\n", proc->instr->new_pc - vm->arena[0]);
	#if 0
	ft_log("\t\tarena[%d + (%d+%d) %% IDX_MOD] = %d --> reg[%d]\n",
						proc->pc - vm->arena[0],
						proc->instr->args[1].data,
						proc->instr->args[2].data,
						proc->reg[proc->instr->args[0].data],
						proc->instr->args[0].data);
	ft_log("\t\t------------------------------- %4d\n", proc->pc - vm->arena[0]);
	#endif
	#if 0
	ft_log("\t\tarena[%d + %d] = %d --> reg[%d]\n",
						proc->instr->args[1].data,
						proc->instr->args[2].data,
						proc->reg[proc->instr->args[0].data],
						proc->instr->args[0].data);
	ft_log("\t\t------------------------------- %4d\n", proc->pc - vm->arena[0]);
	#endif
}
	#if 0
	ft_log("  Cycle %-7d Player %d --- %-5s\n", vm->current_cycle,
		-proc->process_nb, "sti");
	//ft_vm_log_arg(proc);
	ft_log("\t\tarena[%d + %d] = %d --> reg[%d]\n",
						copy_at_address[0], copy_at_address[1],
						vm->arena[0][MOD(copy_at_address[0] + copy_at_address[1])],
						*(proc->pc + 2));
						#endif
