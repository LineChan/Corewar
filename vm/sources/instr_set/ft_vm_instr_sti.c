/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:56:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/07 17:49:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO: presentation
/*
* brief      		Execute sti : Take a registry and 2 indexes
* (potentially registries), add the two indexes and use this result
* as an address where the value of the first parameter will be copied.
*
* param arena
* param champ
*/

extern uint8_t	g_direct_jump_table_from_instr[17];

// TODO : remove libc.h
#include <libc.h>
void 			ft_vm_instr_sti(unsigned char arena[],
                                t_dead_pool *dead_pool,
                                t_champion *champ)
{
    int             i;
    int             reg;
    int             copy_at_address;
    unsigned char   *ptr;

    (void)dead_pool;
    DEBUG_MODE ? ft_printf("{yellow:sti}\n") : 0;
    i = 1;
    copy_at_address = 0;
    ptr = champ->pc + 2;
    reg = *ptr;
    DEBUG_MODE ? ft_printf("reg : %hhx\n", reg) : 0;
    ptr += champ->instr.arg_jump[0];
    while (i < champ->instr.op->nb_args)
    {
        if (champ->instr.op->arg_types[i] == T_REG)
            copy_at_address += champ->reg[*ptr];
        else if (champ->instr.op->arg_types[i] == T_IND)
            copy_at_address += ft_instruction_get_data(2, ptr);
        else
            copy_at_address += ft_instruction_get_data(g_direct_jump_table_from_instr[champ->instr.op->numero], ptr);
        ptr += champ->instr.arg_jump[i];
        ++i;
    }
    DEBUG_MODE ? ft_printf("final copy_at_address : %d\n", copy_at_address) : 0;
    arena[MOD(copy_at_address)] = champ->reg[reg];
    champ->pc += 2 + champ->instr.arg_jump[0] + champ->instr.arg_jump[1] + champ->instr.arg_jump[2];
    DEBUG_MODE ? getchar() : 0;
}
