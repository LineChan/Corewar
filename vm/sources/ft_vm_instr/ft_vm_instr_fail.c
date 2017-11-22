/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_fail.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:26:41 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 17:47:19 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief      			Move the Program Counter and update the next cycle
*						if the execution fails
*
* param arena			Memory dedicated to the Virtual Machine
* param dead_pool		t_dead_pool struct for the game
* param nb_champion		Number of alive champions in the arena
*/

void 				ft_vm_instr_fail(t_champion *i_champ, int carry)
{
	i_champ->pc += 1;
	i_champ->next_cycle += 1;
	(carry == CARRY_CHANGE) ? (i_champ->carry = 1) : 0;
}
