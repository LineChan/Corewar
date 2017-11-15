/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_check_if_done.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:09:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/15 17:45:55 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentation and libc
#include <libc.h>

int 				ft_vm_instr_check_if_done(t_dead_pool *dead_pool,
												int *nb_champion)
{
	t_list		*it;

	ft_printf("{bblack:ft_vm_instr_check_if_done} {green:in}\n");
	if (ft_list_is_empty(&dead_pool->champ[CHAMP_IDX].process_head))
	{
		if (dead_pool->champ[CHAMP_IDX].next_cycle > dead_pool->current_cycle)
		{
			dead_pool->champ[CHAMP_IDX].done = 1;
			if (ft_vm_instr_end_of_game(dead_pool, nb_champion) == EXIT_SUCCESS)
			{
				ft_printf("{bblack:ft_vm_instr_check_if_done} {green:out no sub}\n\t");
				return (EXIT_SUCCESS);
			}
		}
		ft_printf("{bblack:ft_vm_instr_check_if_done} {red:out no sub}\n\t");
		return (EXIT_FAILURE);
	}
	//dead_pool->i_champ = dead_pool->champ[CHAMP_IDX].process_head.next;
	it = dead_pool->champ[CHAMP_IDX].process_head.next;
	while (it != &dead_pool->champ[CHAMP_IDX].process_head)
	{
		if (!C_PROCESS(it)->process.done)
		{
			if (C_PROCESS(it)->process.next_cycle
						<= dead_pool->current_cycle)
			{
				ft_printf("{bblack:ft_vm_instr_check_if_done} {red:out with sub}\n\t");
				return (EXIT_FAILURE);
			}
		}
		it = it->next;
	}
	ft_printf("{bblack:ft_vm_instr_check_if_done} {green:out with sub}\n");
	return (EXIT_SUCCESS);
}
