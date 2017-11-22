/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:01:16 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 01:04:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief      		Read each champion's name
*
* param dead_pool		t_dead_pool struct for the game
*/

void            ft_vm_read_header_name(t_dead_pool *dead_pool)
{
    if (IS_NEG(read(dead_pool->option.fd[dead_pool->idx],
        dead_pool->champ[dead_pool->idx].header.prog_name,
        ALIGN_4(sizeof(dead_pool->i_champ->header.prog_name)))))
        EXIT_FAIL("Error : champion's name can't be read");
        ft_printf("header.name = %s\n", dead_pool->champ[dead_pool->idx].header.prog_name);
}
