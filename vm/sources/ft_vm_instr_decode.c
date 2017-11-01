/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:28:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/01 14:53:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"
//TODO: presentation

void				ft_vm_instr_decode(unsigned char arena[], t_champion *champ)
{
   (void)arena;
   champ->instr.op = &g_op_tab[*champ->pc];
   champ->instr.index = *champ->pc;
   (champ->instr.op->nb_args) ? ft_vm_instr_bytecode(champ) : 0;
   ft_vm_instr_jump(champ);
   champ->pc += champ->instr.jump;
   champ->next_cycle += champ->instr.op->nb_cycles;
   if (DEBUG_MODE)
   {
	   ft_printf("champion->op.name : '%s'\n", champ->instr.op->name);
	   ft_printf("champ->instr.jump : %d\n", champ->instr.jump);
	   ft_printf("champion->live : %d\n", champ->live);
	   ft_printf("before jump : %hhx\n", arena[*champ->pc]);
	   ft_printf("after jump : %hhx\n", *champ->pc);
   }
}
