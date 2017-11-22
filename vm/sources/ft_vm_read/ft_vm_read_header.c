/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:28:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 01:04:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      		Read each champion's header
*
* param dead_pool		t_dead_pool struct for the game
* param nb_champion		Champions' number
*/

void	ft_vm_read_header(t_dead_pool *dead_pool,
							unsigned int *nb_champion)
{
	*nb_champion = 0;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		ft_printf("header idx: %d\n", dead_pool->idx);
		if (dead_pool->option.fd[dead_pool->idx])
		{
			++*nb_champion;
			ft_vm_read_header_magic(dead_pool);
			ft_vm_read_header_name(dead_pool);
			ft_vm_read_header_size(dead_pool);
			ft_vm_read_header_comment(dead_pool);
		}
		++dead_pool->idx;
	}
}
