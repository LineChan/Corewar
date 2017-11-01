/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:56:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/01 18:55:25 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

void 			ft_vm_instr_sti(unsigned char arena[], t_champion *champ)
{
    DEBUG_MODE ? ft_printf("{yellow:sti}\n") : 0;
    int reg_number;
    int address;

    address = 0;
    if (!(champ->instr.op->arg_types[0] == T_REG))
        EXIT_FAIL("Error : wrong arg file");
    reg_number = *champ->pc;
    DEBUG_MODE ? ft_printf("reg_number : %d\n", reg_number) : 0;
    champ->pc += champ->instr.arg_jump[0];
    DEBUG_MODE ? ft_printf("jump : %d next arg : %x\n", champ->instr.arg_jump[0], *champ->pc) : 0;

    // TODO : check if correct
    if (champ->instr.op->arg_types[1] == T_REG)
    {
        address += champ->reg[*champ->pc];
        champ->pc += champ->instr.arg_jump[1];
        ft_printf("address : %d\n", address);
    }
    else if (champ->instr.op->arg_type[1] == T_DIR)
    {

    }


    (void)arena;
}
