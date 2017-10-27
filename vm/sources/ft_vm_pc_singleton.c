/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_pc_singleton.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:47:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/27 16:01:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
 * brief      		Singleton gathering each champion's Program Counter
 */

 #define INIT_LST_HEAD(it)			(it).next = (it).prev = &(it)
 # define INIT_LST_HEAD_P(it)		(it)->next = (it)->prev = it;

t_champion			*ft_champion1(void)
{
	static t_champion		*ptr = NULL;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_champion))))
		INIT_LST_HEAD(ptr->champion_head);
	return (ptr);
}

t_champion			*ft_champion2(void)
{
	static t_champion		*ptr = NULL;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_champion))))
		INIT_LST_HEAD_P(&ptr->champion_head);
	return (ptr);
}

t_champion			*ft_champion3(void)
{
	static t_champion		*ptr = NULL;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_champion))))
		INIT_LST_HEAD_P(&ptr->champion_head);
	return (ptr);
}

t_champion			*ft_champion4(void)
{
	static t_champion		*ptr = NULL;

	if (!ptr && (ptr = ft_memalloc(sizeof(t_champion))))
		INIT_LST_HEAD_P(&ptr->champion_head);
	return (ptr);
}

void				ft_del_singl_champ(t_list *champion)
{
	t_champion			*ptr;

	ptr = C_CHAMP(champion);
	if (!ft_list_is_empty(&ptr->champion_head))
		ft_list_apply(&ptr->champion_head, &ft_vm_instr_del);
}
