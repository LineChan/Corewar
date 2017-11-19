/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_st.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 21:42:00 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/18 23:34:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

// TODO: presentation
/*
* brief      		Log function for the ld instruction
*
*/

void 				ft_vm_log_st(t_dead_pool *dead_pool,
									unsigned char arena[],
									int dir)
{
	if (dir == T_DIR)
		ft_log("  Cycle %-7d Player %d --- %-5s : arena[%d] = %d \n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "st", MOD((dead_pool->i_champ->pc - arena) + (ft_instruction_get_data(2, dead_pool->i_champ->pc + 3) % IDX_MOD)), arena[MOD((dead_pool->i_champ->pc - arena) + (ft_instruction_get_data(2, dead_pool->i_champ->pc + 3) % IDX_MOD))]);
	else
		ft_log("  Cycle %-7d Player %d --- %-5s : arena[%d] = %d \n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "st", *(dead_pool->i_champ->pc + 3), dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 3)]);
}
