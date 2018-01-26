/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_ld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:07:56 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/26 01:29:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "endian.h"

#include "ft_printf.h"
void			ft_instr_ld(t_vm *vm, t_proc *proc)
{
	if (proc->instr->args[0].type == T_IND)
	{
		proc->instr->args[0].data =
		//ft_arena_get_int8(vm, proc->pc + (proc->instr->args[0].data % IDX_MOD));
			#if 1
			ft_instr_get_data(vm, REG_SIZE,
				&vm->arena[0][proc->pc + (proc->instr->args[0].data % IDX_MOD)],
				IS_BIG_ENDIAN);
			#endif
	}
	/* Load the value in a resgister */
	proc->reg[proc->instr->args[1].data] = proc->instr->args[0].data;
	/* Display additionnal informations */
	if (DISP_OPT)
		ft_display_ld_lld(vm, proc);
	/* Change the carry */
	proc->carry = !proc->reg[proc->instr->args[1].data];
}
