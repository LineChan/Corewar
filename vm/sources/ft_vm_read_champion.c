/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_champion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:28:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/22 19:16:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/**
 * \fn void ft_vm_read_champion(int option[], t_header header[])
 * \brief Read champions' binaries
 *
 * \param option
 * \param dead_pool
 * \return None
 */

 void		ft_vm_read_routine(t_header *champion, const int fd)
 {
	ft_vm_read_dead_pool_magic(champion, fd);
	ft_vm_read_dead_pool_name(champion, fd);
	ft_vm_read_dead_pool_size(champion, fd);
	ft_vm_read_dead_pool_comment(champion, fd);
 }

void		ft_vm_read_champion(int option[], t_dead_pool *dead_pool)
{
	ft_memset((void *)dead_pool, 0, sizeof(t_dead_pool));
	if (option[1])
		ft_vm_read_routine(&dead_pool->champion1, option[1]);
	if (option[2])
		ft_vm_read_routine(&dead_pool->champion2, option[2]);
	if (option[3])
		ft_vm_read_routine(&dead_pool->champion3, option[3]);
	if (option[4])
		ft_vm_read_routine(&dead_pool->champion4, option[4]);
}
