/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:57:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/28 17:55:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void                ft_vm_instr_sti(t_vm *vm, t_process *proc)
{
	int					i;
	int					copy_at_address;
	unsigned char		*ptr;
	extern t_op			g_op_tab[17];
	extern uint8_t		g_direct_jump_table_from_instr[17];
	
	copy_at_address = 0;
	/* Set a pointer at the beginning of the arguments */
	ptr = proc->pc + 2;
	/* Read arguments */
	if (!IS_REG(*ptr))
	{
		ft_vm_instr_fail(proc, !CARRY_CHANGE);
		return ;
	}
	ptr += proc->jump[0];
	i = 1;
	while (i < proc->op->nb_args)
	{
		if (proc->op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				ft_vm_instr_fail(proc, !CARRY_CHANGE);
				return ;
			}
			copy_at_address += proc->reg[*ptr];
		}
		else if (proc->op->arg_types[i] == T_IND)
		{
			ft_log("get_data : %d\n", ft_instruction_get_data(2, ptr));
			copy_at_address += proc->pc - vm->arena[0] + (ft_instruction_get_data(2, ptr) % IDX_MOD);
			ft_log("copy_at_address : %d\n", copy_at_address);
		}
		else if (proc->op->arg_types[i] == T_DIR)
		{
			copy_at_address += ft_instruction_get_data(g_direct_jump_table_from_instr[proc->op->numero], ptr);
			ft_log("copy_at_address : %d\n", copy_at_address);
		}
		ptr += proc->jump[i];
		++i;
	}
	/* Load a value from a register */
	vm->arena[0][MOD(copy_at_address)] = proc->reg[*(proc->pc + 2)];
	/* Write in a logfile */
	LOG_OPT ? ft_vm_log_sti(vm, proc, copy_at_address) : 0;
	/* Fetch the next instruction */
	proc->pc += 2 + proc->jump[0] + proc->jump[1] + proc->jump[2];
}
