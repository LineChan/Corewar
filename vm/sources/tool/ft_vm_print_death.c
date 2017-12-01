/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_print_death.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:01:32 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/01 18:17:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO: libs
#include "ft_printf.h"

void			ft_vm_print_death(t_vm *vm,
									const unsigned int cycle_end_round,
									const int cycle_to_die)
{
	t_list		*it;

	it = vm->process_head.next;
	ft_printf("print death\n");
	//TODO : PB BC everything removed;
	while (it != &vm->process_head)
	{
		ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
			C_PROCESS(it)->parent_nb, C_PROCESS(it)->live[1] - cycle_end_round,
			cycle_to_die);
		it = it->next;
	}
}
