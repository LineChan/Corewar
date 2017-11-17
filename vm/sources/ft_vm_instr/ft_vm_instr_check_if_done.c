/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_check_if_done.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:09:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 14:14:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentation

int 				ft_vm_instr_check_if_done(t_dead_pool *dead_pool)
{
	t_list		*it;

	ft_printf("{bblack:ft_vm_instr_check_if_done} {green:in}\n");
	/* Check if the champion has subprocesses */
	if (!ft_list_is_empty(&dead_pool->champ[CHAMP_IDX].process_head))
	{
		it = dead_pool->champ[CHAMP_IDX].process_head.next;
		while (it != &dead_pool->champ[CHAMP_IDX].process_head)
		{
			/* If we find an undone process, the champion hasn't finish to play */
			if (!C_PROCESS(it)->process.done)
				return (EXIT_FAILURE);
			it = it->next;
		}
	}
	/* Check if the champion has executed all its instruction */
	if (dead_pool->champ[CHAMP_IDX].next_cycle <= dead_pool->current_cycle)
		return (EXIT_FAILURE);
	dead_pool->champ[CHAMP_IDX].done = 1;
	return (EXIT_SUCCESS);
}
