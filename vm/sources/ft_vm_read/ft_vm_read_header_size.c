/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:20:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 00:30:31 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief      		Read each champion's size
*
* param dead_pool		t_dead_pool struct for the game
*/

void 			ft_vm_read_header_size(t_dead_pool *dead_pool)
{
	if (IS_NEG(read(dead_pool->option.fd[dead_pool->idx],
		&dead_pool->champ[dead_pool->idx].header.prog_size,
		sizeof(dead_pool->i_champ->header.prog_size))))
		EXIT_FAIL("Error : champion's size can't be read");
	if (IS_LITTLE_ENDIAN)
		dead_pool->champ[dead_pool->idx].header.prog_size =
		ft_endian_convert_uint32(dead_pool->champ[dead_pool->idx].header.prog_size);
	if (dead_pool->champ[dead_pool->idx].header.prog_size > CHAMP_MAX_SIZE)
		EXIT_FAIL("Error : champion's size too big");
}
