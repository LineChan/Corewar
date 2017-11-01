/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:28:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/01 18:55:56 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO: presentation

void				ft_vm_instr_decode(t_champion *champ)
{
   champ->instr.op = &g_op_tab[*champ->pc];
   champ->instr.index = *champ->pc;
   (champ->instr.op->param_byte) ? ft_vm_instr_bytecode(champ) : 0;
   ft_vm_instr_jump(champ);
   //champ->pc += 1;
   champ->next_cycle += champ->instr.op->nb_cycles;
   if (DEBUG_MODE)
   {
	   ft_printf("champion->op.name : '%s'\n", champ->instr.op->name);
	   ft_printf("champion->live : %d\n", champ->live);
   }
}
