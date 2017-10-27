/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_champion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:28:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/27 16:04:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      		Read each champion's hearder
*
* param option		Options array
* param dead_pool	Structure gathering all the champions
* param nb_champion	Champions' number
*/

 void		ft_vm_read_header(t_header *champion, const int fd)
 {
	ft_vm_read_dead_pool_magic(champion, fd);
	ft_vm_read_dead_pool_name(champion, fd);
	ft_vm_read_dead_pool_size(champion, fd);
	ft_vm_read_dead_pool_comment(champion, fd);
 }

void	ft_vm_read_champion(int option[],
							t_dead_pool *dead_pool,
							int *nb_champion)
{
	ft_memset((void *)dead_pool, 0, sizeof(*dead_pool));
	*nb_champion = 0;
	if (option[1] && ++*nb_champion)
		ft_vm_read_header(&dead_pool->champion1, option[1]);
	if (option[2] && ++*nb_champion)
		ft_vm_read_header(&dead_pool->champion2, option[2]);
	if (option[3] && ++*nb_champion)
		ft_vm_read_header(&dead_pool->champion3, option[3]);
	if (option[4] && ++*nb_champion)
		ft_vm_read_header(&dead_pool->champion4, option[4]);
}
