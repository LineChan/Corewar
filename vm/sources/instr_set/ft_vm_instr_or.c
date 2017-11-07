/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_or.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 00:29:36 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/07 17:45:35 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentation
/*
* brief      		Execute or : Apply an | (bit-to-bit OR) over the first
* two arguments and store the result in a registry, which is the third argument. It will change the carry.
*
* param arena
* param champ
*/
//TODO : carry
//TODO : remove libc.h
#include <libc.h>
extern uint8_t	g_direct_jump_table_from_instr[17];

void			ft_vm_instr_or(unsigned char arena[],
                                t_dead_pool *dead_pool,
                                t_champion *champ)
{
    int                 i;
    unsigned int        or[2];
    unsigned char       *ptr;

    (void)dead_pool;
    ptr = champ->pc + 2;
    i = 0;
    DEBUG_MODE ? ft_printf("{yellow:or}\n") : 0;
    while (i < (champ->instr.op->nb_args - 1))
    {
        if (champ->instr.op->arg_types[i] == T_REG)
            or[i] = champ->reg[*ptr];
        else if (champ->instr.op->arg_types[i] == T_IND)
            or[i] = arena[MOD(champ->pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD))];
        else
            or[i] = arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr[champ->instr.op->numero], ptr))];
        ptr += champ->instr.arg_jump[i];
        ++i;
    }
    champ->reg[*ptr] = or[0] | or[1];
	DEBUG_MODE ? ft_printf("reg[%c] : or[0] : %d or[1] : %d ----> & %d \n", *ptr, or[0] , or[1], or[0] | or[1]) : 0;
    champ->pc += 2 + champ->instr.arg_jump[0] + champ->instr.arg_jump[1] + champ->instr.arg_jump[2];
    if (DEBUG_MODE)
    {
        ft_vm_print_reg(champ);
        getchar();
    }
}
