/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:56:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/02 10:21:18 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "ft_vm.h"

// TODO: presentation
/*
* brief      		Execute sti : Take a registry and 2 indexes
* (potentially registries), add the two indexes and use this result
* as an address where the value of the first parameter will be copied.
*
* param arena
* param champ
*/

// TODO : check function
void 			ft_vm_instr_sti(unsigned char arena[], t_champion *champ)
{
    DEBUG_MODE ? ft_printf("{yellow:sti}\n") : 0;
    int reg_number;
    int copy_at_address;

    // TODO : good reg ?
    copy_at_address = 0;
    if (!(champ->instr.op->arg_types[0] == T_REG))
        return ;
    reg_number = *champ->pc;
    DEBUG_MODE ? ft_printf("reg_number : %hhx\n", reg_number) : 0;
    champ->pc += champ->instr.arg_jump[0];
    DEBUG_MODE ? ft_printf("jump : %d next arg : %x\n", champ->instr.arg_jump[0], *champ->pc) : 0;

    if (champ->instr.op->arg_types[1] == T_REG)
        copy_at_address += champ->reg[*champ->pc];
    else if (champ->instr.op->arg_types[1] == T_DIR)
        copy_at_address += *champ->pc;
    else if (champ->instr.op->arg_types[1] == T_IND)
        copy_at_address += champ->instr.index + *champ->pc;
    else
        return ;
    champ->pc += champ->instr.arg_jump[1];

    DEBUG_MODE ? ft_printf("copy_at_address : %d\n", copy_at_address) : 0;
    if (champ->instr.op->arg_types[2] == T_REG)
        copy_at_address += champ->reg[*champ->pc];
    else if (champ->instr.op->arg_types[2] == T_DIR)
        copy_at_address += *champ->pc;
    else
        return ;
    champ->pc += champ->instr.arg_jump[2];
    DEBUG_MODE ? ft_printf("copy_at_address : %d\n", copy_at_address) : 0;
    arena[copy_at_address] = champ->reg[reg_number];
}
