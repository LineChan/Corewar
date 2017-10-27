/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:56:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/27 18:02:46 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

// TODO : presentation
/*
* brief      		Set up the virtual machine
*
* param arena		Memory dedicated to the virtual machine
* param option		Options' array
* param dead_pool	Structure gatehering all the champions
* param nb_champion	Champions number
*/

void				ft_vm_instr_add(unsigned char arena[], t_champion *champ)
{
	t_vm_instr		*new;

	if (!(new = ft_memalloc(sizeof(t_vm_instr))))
		EXIT_FAIL("Error : Memory allocation");
	//TODO : bytecode, jump
	ft_printf("code : %b\n", *champ->pc);
	ft_printf("code : %d\n", *champ->pc);
	if (!NO_BCODE(champ))
		ft_vm_instr_bytecode(champ);
		ft_printf("{red:BYCODE NEEDED}\n");

	#if 0
	ft_printf("NO_BCODE(champ) : %b\n", NO_BCODE(champ));
	ft_printf("LIVE (champ) : %b\tIS_LIVE(champ) : %x\n",LIVE, IS_LIVE(champ));
	ft_printf("IS_ZJUMP(champ) : %b\n", IS_ZJUMP(champ));
	ft_printf("IS_FORK(champ) : %b\n", IS_FORK(champ));
	ft_printf("IS_AFF(champ) : %b\n", IS_AFF(champ));
	//ft_printf("IS_LIVE(champ) : %d\n", IS_LIVE(champ));
	if (!NO_BCODE(champ))
		ft_printf("STI!!!\n");
	#endif
	new->op = &g_op_tab[*champ->pc];
	new->index = champ->pc - arena;
	ft_list_add_tail(&new->list, &champ->champion_head);
	//return (jump) to move PC += jump
}

void				ft_vm_instr_del(t_list *src)
{
	t_vm_instr			*ptr;

	ptr = C_INSTR(src);
	if (!ptr)
		return ;
	ft_list_del(src);
	ft_memdel((void **)&ptr);
}
