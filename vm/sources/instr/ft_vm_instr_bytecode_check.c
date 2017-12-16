/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_bytecode_check.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:40:49 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/25 17:02:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#define BYTECODE_GET(bc, pos)	(((bc) >> (8 - ((pos) << 1))) & 0x3)

int			ft_vm_instr_bytecode_check(t_process *proc)
{
    int                 i;
    extern uint8_t      g_direct_jump_table_from_instr[17];

    i = 0;
    while (i < proc->op->nb_args)
    {

        if (BYTECODE_GET(proc->bytecode, i + 1) == IND_CODE)
        {
            proc->op->arg_types[i] = T_IND;
            proc->jump[i] = 2;
        }
        else if (BYTECODE_GET(proc->bytecode, i + 1) == REG_CODE)
        {
            proc->op->arg_types[i] = T_REG;
            proc->jump[i] = 1;
        }
        else if (BYTECODE_GET(proc->bytecode, i + 1) == DIR_CODE)
        {
            proc->op->arg_types[i] = T_DIR;
            proc->jump[i] = g_direct_jump_table_from_instr[proc->op->numero];
        }
        else
            return (EXIT_FAILURE);
        ++i;
    }
    return (EXIT_SUCCESS);
}
