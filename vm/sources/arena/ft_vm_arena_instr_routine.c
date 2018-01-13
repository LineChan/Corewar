/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_instr_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 23:15:20 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/13 14:58:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_string.h"

//TODO : Libraries
#include "ft_printf.h"
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
	uint8_t			ret;

	ret = ft_instruction_decode(vm, proc);
	//ft_printf("process : %d next_op : %d\n", -proc->process_nb, proc->next_op);
	#if 0
	ft_printf("cycle : %d proc : %d with ret : %d\n", vm->current_cycle, -proc->process_nb, ret);
	ft_printf("next_op : %d \n", proc->next_op);
	#endif
	if (ret == OPCODE_NOT_VALID)
	{
		/* Move the Program Counter to the next byte */
		++proc->pc;
	}
	else if (ret == EXIT_FAILURE)
	{
		/* The OP number is valid, */
		/* but an error was found while decoding the instruction */

		/* Display additional informations */
		#if 0
		if (DISPLAY_16)
			ft_vm_display_pc(vm, proc, proc->instr);
			#endif
		/* Fetch the new instruction */
		/*
		if ((proc->instr->new_pc - vm->arena[0]) > MEM_SIZE)
			proc->instr->new_pc = vm->arena[0] + ((proc->instr->new_pc - vm->arena[0]) % MEM_SIZE);
		*/
		proc->pc = proc->instr->new_pc;
	}
	else
	{
		//ft_printf("execute fork\n");
		/* Execute the decoded instruction */
		g_instr_list[proc->next_op](vm, proc, proc->instr);
	}
	if (proc->pc - vm->arena[0] > MEM_SIZE)
		proc->pc = vm->arena[0] + (proc->pc - vm->arena[0]) % MEM_SIZE;
	//ft_printf("pc is at arena[%d]\n", proc->pc - vm->arena[0]);
	/* Set up the next instruction */
	proc->next_op = *proc->pc;
	/* Update the execution cycle with the new instruction */
	ft_vm_instr_update_exec_cycle(vm, proc);
	//ft_printf("exec_cycle : %d\n", proc->exec_cycle);
	ft_memset((void *)proc->instr, 0, sizeof(t_instr));
	//ft_printf("end turn next_op : %d\n", proc->next_op);
	#if 0
	if ((proc->next_op == 12) || (proc->next_op == 15))
	{
		ft_instruction_decode(vm, proc);
	}
	#endif
}
#if 0
{
	extern t_op		g_op_tab[17];

	if (!proc->instr)
	{
		/* The OP number is invalid */
		/* Move the Program Counter to the next byte */
		++proc->pc;
		/* Update the execution cycle with the new instruction */
		ft_vm_instr_update_exec_cycle(vm, proc);
	}
	else if (proc->error)
	{
		/* The OP number is valid, */
		/* but an error was found while decoding the instruction */

		/* Display additional informations */
		if (DISPLAY_16)
			ft_vm_display_pc(vm, proc, proc->instr);
		/* Fetch the next instruction */
		proc->pc = proc->instr->new_pc;
		/* Update the execution cycle with the new instruction */
		ft_vm_instr_update_exec_cycle(vm, proc);
	}
	else if (ft_vm_instr_check_before_exec(vm, proc))
	{
		/* Execute the decoded instruction */
		g_instr_list[proc->instr->op->numero](vm, proc, proc->instr);
	}
	/* Decode the new instruction */
	ft_instruction_del(&proc->instr);
	ft_instruction_decode(vm, proc);
}
#endif
