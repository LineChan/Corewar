/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:28:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/29 20:59:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"
//TODO: presentation

void				ft_vm_instr_decode(unsigned char arena[], t_champion *champ)
{
   (void)arena;
   champ->instr.op = &g_op_tab[*champ->pc];
   champ->instr.index = *champ->pc;
   ft_printf("champion->op.name : '%s'\n", champ->instr.op->name);
   (champ->instr.op->nb_args) ? ft_vm_instr_bytecode(champ) : 0;
   ft_vm_instr_jump(champ);
   ft_printf("champ->instr.jump : %d\n", champ->instr.jump);
	ft_printf("champion->live : %d\n", champ->live);
   champ->pc += champ->instr.jump;
   ft_printf("{red:segfault}\n");
   ft_printf("after jump : %hhx\n", arena[*champ->pc]);
   ft_printf("{red:segfault}\n");
   //new->op = &g_op_tab[*champ->pc];
   //ft_printf("champ->inst->");
	return ;

   #if 0
   ft_printf("code : %d\n", *champ->pc);
	new->op = &g_op_tab[*champ->pc];
	new->index = champ->pc - arena;
	if (!NO_BCODE(champ))
		ft_vm_instr_bytecode(arena, champ, new);

   ft_vm_instr_add(arena, champ);
   ft_list_apply(&champ->champion_head, &ft_vm_print_instr);
   #endif
}
