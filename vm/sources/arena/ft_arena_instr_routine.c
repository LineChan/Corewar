/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_instr_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:58:32 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 18:12:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_string.h"

#include "ft_printf.h"

static void			ft_instr_default(t_vm *vm, t_proc *proc)
{
	ft_printf("instr default\n");
	(void)proc;
	(void)vm;
	++proc->pc;
}

static const t_func g_instr_list[] =
{
	0,
	&ft_instr_live,
	&ft_instr_ld,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	&ft_instr_default,
	#if 0
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
	#endif
};

#if 0
void			ft_display_arena(void const *data,
								size_t msize,
								size_t nb_byte,
								t_vm *vm)
								#endif
void			ft_arena_instr_routine(t_vm *vm, t_proc *proc)
{
	uint8_t			ret;

	/* Decode the instruction */
	ret = ft_instr_decode(vm, proc);
	if (ret == OPCODE_NOT_VALID)
	{
		//ft_display_arena((void *)&vm->arena[0], MEM_SIZE, 64, vm);
		/* Move the Program Counter to the next byte */
		++proc->pc;
	}
	else if (ret == EXIT_FAILURE)
	{
		/* The OP number is valid, but an error occured while
			decoding the instruction */
		if (DISPLAY_16)
			ft_display_pc(vm, proc);
		proc->pc = proc->instr->new_pc;
	}
	else
	{
		/* Execute the decoded instruction */
		g_instr_list[proc->next_op](vm, proc);
	}
	/* Check if Program Counter isn't out of the arena */
	if (proc->pc >= MEM_SIZE)
		proc->pc %= MEM_SIZE;
	/* Setup the next instructon */
	proc->next_op = vm->arena[0][proc->pc];
	/* Update the execution cycle with the new instruction */
	ft_instr_update_exec_cycle(vm, proc);
	/* Reset the instruction */
	ft_memset((void *)proc->instr, 0, sizeof(t_instr));
}
