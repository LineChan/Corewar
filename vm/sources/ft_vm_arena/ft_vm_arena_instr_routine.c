/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_instr_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:56:20 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/05 13:13:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"
#include "ft_printf.h"

//TODO: libs
#include <libc.h>
#if 0
static void ft_tmp(t_vm *vm, t_process *proc)
{
	(void)vm;
	(void)proc;
	++proc->pc;
	++proc->exec_cycle;
	ft_printf("exec func\n");
	/* code */
}
#endif

static const		t_instr_list g_instr_list [] =
{
	{0},
	{&ft_vm_instr_live},
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
};

void			ft_vm_arena_instr_routine(t_vm *vm, t_process *proc)
{
	extern t_op			g_op_tab[17];

	#if 0
	ft_fprintf(2, "instr routine \n");
	if (vm->current_cycle == 2153)
	{
		ft_vm_print_arena((void *)vm->arena[0], MEM_SIZE, 64, vm);
		ft_printf("\n");
	}
	#endif
	if (!IS_INSTR(*proc->pc))
	{
		/* Move the Program Counter to the next byte */
		proc->pc += 1;
		/* Set the instruction cycle to the next one */
		ft_vm_instr_update_exec_cycle(vm, proc);
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
			/* Move the Program Counter to the next byte */
			proc->pc += 1;
			/* Set the instruction cycle to the next one */
			ft_vm_instr_update_exec_cycle(vm, proc);
			return ;
		}
	}
	/* Execute the decoded instruction */
	g_instr_list[proc->op->numero].func(vm, proc);
	//TODO : ft_vm_notif_instr()
}
