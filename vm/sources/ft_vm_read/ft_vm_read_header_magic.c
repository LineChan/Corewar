/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header_magic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:22:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 01:04:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
/*
* brief      		Read the Magic Number from header
*
* param dead_pool		t_dead_pool struct for the game
*/

void 			ft_vm_read_header_magic(t_dead_pool *dead_pool)
{
    if (IS_NEG(read(dead_pool->option.fd[dead_pool->idx],
        &dead_pool->champ[dead_pool->idx].header.magic,
        sizeof(dead_pool->i_champ->header.magic))))
        EXIT_FAIL("Error : the magic number can't be read");
    if (IS_LITTLE_ENDIAN)
        dead_pool->champ[dead_pool->idx].header.magic =
        ft_endian_convert_uint32(dead_pool->champ[dead_pool->idx].header.magic);
    if (dead_pool->champ[dead_pool->idx].header.magic ^ COREWAR_EXEC_MAGIC)
        EXIT_FAIL("Error : wrong magic number");
}
