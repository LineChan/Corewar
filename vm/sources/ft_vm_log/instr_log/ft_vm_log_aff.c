/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_aff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:03:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 16:20:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO : Presentation
void			ft_vm_log_aff(t_dead_pool *dead_pool)
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "lfork");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\taff : reg[%d] = %c %% 256\n", dead_pool->i_champ->pc + 2, dead_pool->i_champ->reg[*(dead_pool->i_champ->pc + 2)]);
}
