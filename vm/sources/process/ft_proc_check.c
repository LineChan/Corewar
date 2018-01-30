/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:33:21 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/29 15:54:11 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void				ft_proc_check(t_list *it, void *context)
{
	t_vm	*vm;

	/* Setup variables */
	vm = (t_vm *)context;
	/* If the process is still alive and its last live instruction was
		executed during the last round */
	if ((vm->current_cycle - C_PROCESS(it)->has_lived)  >= vm->cycle_to_die)
	{
		/* Delete the process if it did not call the live instruction */
		if (DISPLAY_8)
		{
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					-C_PROCESS(it)->proc_nb ,
					vm->current_cycle - C_PROCESS(it)->has_lived,
					vm->cycle_to_die);
		}
		/* Clean the PC's position for the visual */
		vm->visual.pc_position[C_PROCESS(it)->pc] = 0;
		if ((C_PROCESS(it)->proc_nb == -C_PROCESS(it)->parent_nb) && DISPLAY_32)
			ft_visual_refresh_player_kill(&vm->visual, C_PROCESS(it));
		ft_del_proc(it);
		--vm->nb_proc;
	}

}
