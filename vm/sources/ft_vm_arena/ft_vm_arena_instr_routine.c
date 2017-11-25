/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_instr_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:56:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/25 17:17:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "ft_printf.h"

static void ft_tmp(t_vm *vm, t_process *proc)
{
	(void)vm;
	(void)proc;
	ft_printf("exec func\n");
	/* code */
}
static const		t_instr_list g_instr_list [] =
{
	{0},
	{&ft_vm_instr_live},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	{&ft_tmp},
	#if 0
	{&ft_vm_instr_ld},
	{&ft_vm_instr_st},
	{&ft_vm_instr_add},
	{&ft_vm_instr_sub},
	{&ft_vm_instr_and},
	{&ft_vm_instr_or},
	{&ft_vm_instr_xor},
	{&ft_vm_instr_zjmp},
	{&ft_vm_instr_ldi},
	{&ft_vm_instr_sti},
	{&ft_vm_instr_fork},
	{&ft_vm_instr_lld},
	{&ft_vm_instr_lldi},
	{&ft_vm_instr_lfork},
	{&ft_vm_instr_aff},
	#endif
};

void			ft_vm_arena_instr_routine(t_vm *vm, t_process *proc)
{
	extern t_op			g_op_tab[17];

	(void)vm;
	if (!IS_INSTR(*proc->pc))
	{
		ft_vm_instr_fail(proc, !CARRY_CHANGE);
		return ;
	}
	/* Copy all the informations concerning the instruction */
	proc->op = &g_op_tab[*proc->pc];
	/* Read the bytecode if there is one */
	if (proc->op->param_byte)
	{
		/* Save the bytecode */
		proc->bytecode = (unsigned int)*(proc->pc + 1);
		/* Check if the parameters are valid */
		if (ft_vm_instr_bytecode_check(proc) == EXIT_FAILURE)
		{
			ft_vm_instr_fail(proc, !CARRY_CHANGE);
			return ;
		}
	}
	/* Execute the decoded instruction */
	g_instr_list[proc->op->numero].func(vm, proc);
	//TODO : ft_vm_notif_instr()
}
