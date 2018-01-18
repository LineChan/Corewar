/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:33:49 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 18:12:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

void			ft_instr_live(t_vm *vm, t_proc *proc)
{
	t_list		*it;

	it = 0;
	/* Count of live instructions during the current round */
	++vm->total_live;
	proc->has_lived = vm->current_cycle;
	if ((it = ft_find_proc(&vm->proc_head, proc->instr->args[0].data)))
	{
		vm->last_alive = C_PROCESS(it)->parent_nb;
		//++C_PROCESS(it)->live ----> counting the nb of live instruction ?
		// C_PROCESS(it)->has_lived : pdady corewar, but not sure it matches zaz vm. NEED TO BE CHECKED
	}
	/* Display additional informations */
	if (DISP_OPT)
		ft_display_live(vm, proc, it);
	/* Fetch the next instruction */
	proc->pc = proc->instr->new_pc;
}
