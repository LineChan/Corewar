/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:33:27 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/09 19:02:27 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

extern uint8_t g_direct_jump_table_from_instr[17];
/*
* brief      		Execute sub : Take three registries,
substract the first two, and place the result in the third, right before modifying the carry
*
* param arena
* param champ
*/
//TODO : carry
void            ft_vm_instr_sub(unsigned char arena[], t_dead_pool *dead_pool)
{
    int             i;
    unsigned        sub[3];
    unsigned char   *ptr;

    (void)arena;
    i = 0;
    ptr = dead_pool->i_champ->pc + 2;
    while (i < dead_pool->i_champ->instr.op->nb_args)
    {
        sub[i] = *ptr;
        ++ptr;
        ++i;
    }
    dead_pool->i_champ->reg[sub[2]] = dead_pool->i_champ->reg[sub[0]] - dead_pool->i_champ->reg[sub[1]];
    dead_pool->i_champ->pc += 2 + dead_pool->i_champ->instr.arg_jump[0] + dead_pool->i_champ->instr.arg_jump[1] + dead_pool->i_champ->instr.arg_jump[2];
    if (DEBUG_MODE)
    {
        ft_printf("sub[0] : %d\n", sub[0]);
        ft_printf("sub[1] : %d\n", sub[1]);
        ft_printf("sub[2] : %d\n\n", sub[2]);
        ft_vm_print_reg(dead_pool->i_champ);
        getchar();
    }
}
