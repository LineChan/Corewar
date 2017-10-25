/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_pc_singleton.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:47:22 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/25 17:28:41 by mvillemi         ###   ########.fr       */
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
