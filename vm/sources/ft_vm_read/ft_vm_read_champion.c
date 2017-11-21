/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_champion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:28:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/20 19:37:58 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      		Read each champion's header
*
* param option		Options array
* param dead_pool	Structure gathering all the champions
* param nb_champion	Champions' number
*/

 void		ft_vm_read_header(t_header *header, const int fd)
 {
	ft_vm_read_dead_pool_magic(header, fd);
	ft_vm_read_dead_pool_name(header, fd);
	ft_vm_read_dead_pool_size(header, fd);
	ft_vm_read_dead_pool_comment(header, fd);
 }

void	ft_vm_read_champion(t_dead_pool *dead_pool,
							unsigned int *nb_champion)
{
	(void)dead_pool;
	(void)nb_champion;
	#if 0
	ft_memset((void *)dead_pool, 0, sizeof(*dead_pool));
	*nb_champion = 0;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		if (option[dead_pool->idx + 1])
		{
			++*nb_champion;
			ft_vm_read_header(&dead_pool->champ[dead_pool->idx].header, option[dead_pool->idx + 1]);
		}
		++dead_pool->idx;
	}
	#endif
}
