/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_round_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 00:51:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 01:27:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : libs
#include "ft_printf.h"
#include <libc.h>
void			ft_vm_arena_round_check(t_vm *vm,
										int *nb_champion,
										unsigned int *cycle_to_die)
{
	t_list				*it;
	unsigned int		live_total;

	ft_printf("round_check\n");
	(void)nb_champion;
	(void)cycle_to_die;
	it = vm->process_head.next;
	live_total = 0;
	while (it != &vm->process_head)
	{
		ft_printf("going through loop\n");
		if (!C_PROCESS(it)->live)
		{
			ft_printf("NO LIVES\n");
			ft_vm_close_process(it);
		}
		else
		{
			live_total += C_PROCESS(it)->live;
			ft_printf("check : %d ---> %d lives\n", C_PROCESS(it)->parent_nb,
						C_PROCESS(it)->live);
		}
		it = it->next;
	}
	getchar();
}
