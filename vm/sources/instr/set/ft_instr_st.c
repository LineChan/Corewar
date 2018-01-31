/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_st.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:32:20 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 18:58:56 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

void			ft_instr_st(t_vm *vm, t_proc *proc)
{
	/* Display additional informations */
	if (DISPLAY_4)
	{
		ft_printf("P %4d | st r%d %d\n",
				-proc->proc_nb,
				proc->instr->args[0].data,
				proc->instr->args[1].data);

	}
	/* Store the value from a register */
	if (proc->instr->args[1].type == T_REG)
		proc->reg[proc->instr->args[1].data] = proc->reg[proc->instr->args[0].data];
	/* Store the value from arena[PC + arg % IDX_MOD] */
	else
	{
		ft_arena_set_int32(vm, proc->pc + (proc->instr->args[1].data % IDX_MOD),
			proc->reg[proc->instr->args[0].data], proc->parent_nb);
	}
}
