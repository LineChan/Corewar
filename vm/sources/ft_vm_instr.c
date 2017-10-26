/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:56:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/26 16:33:30 by mvillemi         ###   ########.fr       */
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
	INIT_LIST_HEAD(new->list);
	//TODO : bytecode, jump
	new->op = &g_op_tab[*champ->pc];
	new->index = champ->pc - arena;
	ft_printf("new->op->name : %s\n", new->op->name);
	ft_printf("cham : %d\n", champ->carry);
	ft_list_add_tail(&new->list, &champ->champion_head);
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


#if 0

typedef struct			s_vm_instr
{
	uint8_t			bytecode;
	t_op				*op;
	size_t				jump;
	t_list				list;

}						t_vm_instr;
#endif
