/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_instr_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:56:20 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/05 23:17:05 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

static const t_func g_instr_list[] =
{
	0,
	&ft_vm_instr_live,
	&ft_vm_instr_ld,
	&ft_vm_instr_st,
	&ft_vm_instr_add,
	&ft_vm_instr_sub,
	&ft_vm_instr_and,
	&ft_vm_instr_or,
	&ft_vm_instr_xor,
	&ft_vm_instr_zjmp,
	&ft_vm_instr_ldi,
	&ft_vm_instr_sti,
	&ft_vm_instr_fork,
	&ft_vm_instr_lld,
	&ft_vm_instr_lldi,
	&ft_vm_instr_lfork,
	&ft_vm_instr_aff,
};

void			ft_vm_arena_instr_routine(t_vm *vm, t_process *proc)
{
	t_instr			*instr;
	int				error;
	extern t_op		g_op_tab[17];

	//ft_printf("proc %d carry : %d\n", proc->process_nb, proc->carry);
	instr = ft_instruction_decode(proc->pc, vm->arena[0], &error);
	if (0 == instr)
	{
		/* The OP number is invalid */
		/* Move the Program Counter to the next byte */
		++proc->pc;
		/* Set the instruction cycle to the next one */
		if (OPCODE_IS_VALID(*proc->pc))
			proc->exec_cycle += g_op_tab[*proc->pc].nb_cycles;
		else
			++proc->exec_cycle;
		return ;
	}
	else if (0 != error)
	{
		/* The OP number is valid, */
		/* but an error was found while decoding the instruction */
		/* Display additional informations */
		if (DISPLAY_16)
			ft_vm_display_pc(vm, proc, instr);
		/* Fetch the next instruction */
		proc->pc = instr->new_pc;
		// TODO : carry change ?
		// proc->carry = 0;
		/* Update the execution cycle with the new instruction */
		ft_vm_instr_update_exec_cycle(vm, proc);
	}
	else
	{
		/* Execute the decoded instruction */
		g_instr_list[instr->op->numero](vm, proc, instr);
	}
	//TODO : ft_vm_notif_instr()
	ft_instruction_del(&instr);
}
