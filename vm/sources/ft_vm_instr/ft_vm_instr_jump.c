/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_jump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:49:53 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 18:24:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#define BYTECODE_GET(bc, pos)	(((bc) >> (8 - ((pos) << 1))) & 0x3)

/*
* brief      			Compute the jump of the instruction
*
* param i_champ			Pointer on a champion structure
*/

int				ft_vm_instr_jump(t_champion *i_champ)
{
    int                  i;
    extern uint8_t	     g_direct_jump_table_from_instr[17];

    i = 0;
    while (i < i_champ->instr.op->nb_args)
    {
        if (BYTECODE_GET(i_champ->instr.bytecode, i + 1) == IND_CODE)
        {
            i_champ->instr.arg_jump[i] = 2;
            i_champ->instr.op->arg_types[i] = T_IND;
        }
        else if (BYTECODE_GET(i_champ->instr.bytecode, i + 1) == REG_CODE)
        {
            i_champ->instr.arg_jump[i] = 1;
            i_champ->instr.op->arg_types[i] = T_REG;
        }
        else if (BYTECODE_GET(i_champ->instr.bytecode, i + 1) == DIR_CODE)
        {
            i_champ->instr.arg_jump[i] = 1;
            i_champ->instr.op->arg_types[i] = T_DIR;
        }
        else
        {
            ft_vm_instr_fail(i_champ, !CARRY_CHANGE);
            return (EXIT_FAILURE);
        }
        ++i;
    }
    return (EXIT_SUCCESS);
}
