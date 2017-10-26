/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_pc_singleton.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:47:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/26 16:33:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
 * brief      		Singleton gathering each champion's Program Counter
 */

t_champion			*ft_champion1(void)
{
	static t_champion		ptr;

	return (&ptr);
}

t_champion			*ft_champion2(void)
{
	static t_champion	ptr;

	return (&ptr);
}

t_champion			*ft_champion3(void)
{
	static t_champion	ptr;

	return (&ptr);
}

t_champion			*ft_champion4(void)
{
	static t_champion	ptr;

		return (&ptr);
}

void				ft_del_singl_champ(t_list *champion)
{
	t_champion			*ptr;

	ptr = C_CHAMP(champion);
	if (!ft_list_is_empty(&ptr->champion_head))
		ft_list_apply(&ptr->champion_head, &ft_vm_instr_del);
	ft_memdel((void **)&ptr);
}
