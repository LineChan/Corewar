/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_xor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 00:52:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 16:48:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

//TODO:presentation
void 				ft_vm_log_xor(t_dead_pool *dead_pool,
									unsigned char *ptr,
									unsigned int xor[])
{
	ft_log("  Cycle %-7d Player %d --- %-5s\n", dead_pool->i_champ->next_cycle, CHAMP_IDX + 1, "xor");
	ft_vm_log_arg(dead_pool);
	ft_log("\t\treg[%d] = %d --> [%d] ^ [%d]\n", *ptr, dead_pool->i_champ->reg[*ptr], xor[0], xor[1]);
}
