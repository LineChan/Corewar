/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_zjmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:48:01 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/27 17:57:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_instr_zjmp(t_vm *vm, t_process *proc)
{
	extern uint8_t g_direct_jump_table_from_instr[17];
	extern t_op		g_op_tab[17];

	/* Execute the instruction only if the carry value is 1 */
	if (proc->carry)
		proc->pc += MOD((proc->pc - vm->arena[0] + (ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero], proc->pc + 1) % IDX_MOD)));
	LOG_OPT ? ft_vm_log_zjmp(vm, proc) : 0;
}
