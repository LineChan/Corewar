/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header_comment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 00:31:59 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 01:04:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief      		Read each champion's comment
*
* param dead_pool		t_dead_pool struct for the game
*/

void				ft_vm_read_header_comment(t_dead_pool *dead_pool)
{

    if (IS_NEG(read(dead_pool->option.fd[dead_pool->idx],
        dead_pool->champ[dead_pool->idx].header.comment,
        ALIGN_4(sizeof(dead_pool->i_champ->header.comment)))))
        EXIT_FAIL("Error : champion's name can't be read");
}
