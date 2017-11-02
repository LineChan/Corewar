/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:28:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/02 16:03:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO: presentation

int					ft_vm_instr_decode(unsigned char arena[], t_champion *champ)
{
   champ->instr.op = &g_op_tab[*champ->pc];
   champ->instr.index = champ->pc - arena;
   (champ->instr.op->param_byte) ? ft_vm_instr_bytecode(champ) : 0;
   if (ft_vm_instr_jump(champ) == EXIT_FAILURE)
   	return (EXIT_FAILURE);
   champ->next_cycle += champ->instr.op->nb_cycles;
   if (DEBUG_MODE)
   {
	   ft_printf("champion->op.name : '%s'\n", champ->instr.op->name);
	   ft_printf("champion->live : %d\n", champ->live);
   }
   return (EXIT_SUCCESS);
}
