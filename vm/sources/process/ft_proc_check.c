/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 16:33:21 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/24 18:22:56 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void				ft_proc_check(t_list *it, void *context)
{
	t_vm	*vm;
	//int		offset;

	/* Setup variables */
	vm = (t_vm *)context;

	//offset = vm->current_cycle - C_PROCESS(it)->has_lived;
	/* If the process is still alive and its last live instruction was
		executed during the last round */
	//if ((int)C_PROCESS(it)->has_lived < (vm->current_cycle - vm->cycle_to_die))
	if ((vm->current_cycle - C_PROCESS(it)->has_lived)  >= vm->cycle_to_die)
	{
		/* Delete the process if it did not call the live instruction */
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
				-C_PROCESS(it)->proc_nb ,
				vm->current_cycle - C_PROCESS(it)->has_lived,
				//offset,
				vm->cycle_to_die);
		ft_del_proc(it);
		--vm->nb_proc;
	}

}
