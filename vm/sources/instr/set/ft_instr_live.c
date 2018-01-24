/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:33:49 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/24 18:08:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"
#include "ft_printf.h"

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
	//t_list		*it;

	//it = 0;
	//int			i;
	/* Count of live instructions during the current round */
	++vm->total_live;
	proc->has_lived = vm->current_cycle;
	/* Display the instruction */
	if (DISPLAY_4)
	{
		ft_printf("P %4d | live %d\n",
			-proc->proc_nb, proc->instr->args[0].data);
	}
	#if 0
	if ((proc->instr->args[0].data > -5) && (proc->instr->args[0].data < 0))
	{
		vm->last_alive = -(proc->instr->args[0].data - 1);
	}
	#endif

	if ((proc->instr->args[0].data >= -MAX_PLAYERS) && (proc->instr->args[0].data < 0))
	{
		vm->last_alive = -proc->instr->args[0].data;
		//vm->last_alive = C_PROCESS(it)->parent_nb;
		//++C_PROCESS(it)->live;
		//++C_PROCESS(it)->live ----> counting the nb of live instruction ?
		// C_PROCESS(it)->has_lived : pdady corewar, but not sure it matches zaz vm. NEED TO BE CHECKED

		if (DISPLAY_1)
		{
			ft_printf("Player %d (%s) is said to be alive\n",
						-proc->instr->args[0].data,
						vm->header[-proc->instr->args[0].data - 1].prog_name);
		}

	}
	if (DISPLAY_8)
		vm->opt.death[proc->parent_nb - 1] = vm->current_cycle;
	if (DISPLAY_16)
		ft_display_pc(vm, proc);
	//if (proc->instr->args[0])
	//if ((it = ft_find_proc(&vm->proc_head, proc->instr->args[0].data)))
	/* Display additional informations */
	#if 0
	if (DISP_OPT)
		ft_display_live(vm, proc, it);
		#endif
}
#endif
