/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_instr_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:58:32 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/28 21:43:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

static const t_func g_instr_list[] =
{
	0,
	&ft_instr_live,
	&ft_instr_ld,
	&ft_instr_st,
	&ft_instr_add,
	&ft_instr_sub,
	&ft_instr_and,
	&ft_instr_or,
	&ft_instr_xor,
	&ft_instr_zjmp,
	&ft_instr_ldi,
	&ft_instr_sti,
	&ft_instr_fork,
	&ft_instr_lld,
	&ft_instr_lldi,
	&ft_instr_lfork,
	&ft_instr_aff,
};

void			ft_arena_instr_routine(t_list *it, void *context)
{
	extern t_op			g_op_tab[17];
	t_vm				*vm;
	t_proc				*proc;

	/* Setup variables */
	vm = (t_vm *)context;
	proc = C_PROCESS(it);
	if (!OPCODE_IS_VALID(proc->next_op))
	{
		proc->next_op = vm->arena[proc->pc];
		if (OPCODE_IS_VALID(proc->next_op))
			proc->exec_cycle += g_op_tab[proc->next_op].nb_cycles;
		else
		{
			if (DISPLAY_32)
			{
				#if 0
				vm->arena[1][proc->pc] -= MAX_PLAYERS;
				vm->arena[1][proc->pc + 1] += MAX_PLAYERS;
				ft_curse_refresh_arena(vm);
				#endif
			}
			proc->pc = LOOP(proc->pc + 1);
			++proc->exec_cycle;
		}
		return ;
	}
	if (proc->exec_cycle != vm->current_cycle)
		return ;
	/* Decode arguments and check their validity */
	if (ft_instr_decode(vm, proc) == EXIT_SUCCESS)
		g_instr_list[proc->next_op](vm, proc);
	if (DISPLAY_16 && !proc->instr->zjmp_success)
		ft_display_pc(vm, proc);
	if (DISPLAY_32)
	{
		#if 0
		vm->arena[1][proc->pc] -= MAX_PLAYERS;
		vm->arena[1][proc->instr->new_pc] += proc->parent_nb + MAX_PLAYERS;
		ft_curse_refresh_arena(vm);
		#endif
	}
	/* Fetch the new instruction */
	proc->pc = proc->instr->new_pc;
	proc->next_op = 0;
}
