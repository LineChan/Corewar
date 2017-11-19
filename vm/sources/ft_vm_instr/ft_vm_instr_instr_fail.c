/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_instr_fail.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:48:01 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 15:59:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO:presentation
void 				ft_vm_instr_fail(t_dead_pool *dead_pool,
											int carry)
{
	dead_pool->i_champ->pc += 1;
	dead_pool->i_champ->next_cycle += 1;
	(carry == CARRY_CHANGE) ? (dead_pool->i_champ->carry = 1) : 0;
}
