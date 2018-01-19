/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:33:49 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 17:49:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

#if 0
void			ft_instr_live(t_vm *vm, t_proc *proc)
{
	int			i;

	i = 0;
	++vm->total_live;
	while (i < MAX_PLAYERS)
	{
		if (i == proc->instr->args[0].data)
		{

		}
		++i;
	}
}
#endif

#if 1
void			ft_instr_live(t_vm *vm, t_proc *proc)
{
	t_list		*it;

	it = 0;
	/* Count of live instructions during the current round */
	++vm->total_live;
	proc->has_lived = vm->current_cycle;
	#if 1
	if ((it = ft_find_proc(&vm->proc_head, proc->instr->args[0].data)))
	{
		vm->last_alive = C_PROCESS(it)->parent_nb;
		++C_PROCESS(it)->live;
		//++C_PROCESS(it)->live ----> counting the nb of live instruction ?
		// C_PROCESS(it)->has_lived : pdady corewar, but not sure it matches zaz vm. NEED TO BE CHECKED
	}
	#endif
	/* Display additional informations */
	if (DISP_OPT)
		ft_display_live(vm, proc, it);
}
#endif
