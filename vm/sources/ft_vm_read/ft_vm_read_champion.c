/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_champion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:28:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/08 13:29:45 by mvillemi         ###   ########.fr       */
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

 void		ft_vm_read_header(t_header *header, const int fd)
 {
	ft_vm_read_dead_pool_magic(header, fd);
	ft_vm_read_dead_pool_name(header, fd);
	ft_vm_read_dead_pool_size(header, fd);
	ft_vm_read_dead_pool_comment(header, fd);
 }

void	ft_vm_read_champion(int option[],
							t_dead_pool *dead_pool,
							int *nb_champion)
{
	ft_memset((void *)dead_pool, 0, sizeof(*dead_pool));
	*nb_champion = 0;
	if (option[1] && ++*nb_champion)
		ft_vm_read_header(&dead_pool->champion1.header, option[1]);
	if (option[2] && ++*nb_champion)
		ft_vm_read_header(&dead_pool->champion2.header, option[2]);
	if (option[3] && ++*nb_champion)
		ft_vm_read_header(&dead_pool->champion3.header, option[3]);
	if (option[4] && ++*nb_champion)
		ft_vm_read_header(&dead_pool->champion4.header, option[4]);
}
