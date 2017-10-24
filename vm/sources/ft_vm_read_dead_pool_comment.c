/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_dead_pool_comment.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:27:35 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/24 00:36:08 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      		Read comment from header
*
* param champion	Champion's structure
* param fd			File Descriptor
*/

void			ft_vm_read_dead_pool_comment(t_header *champion, const int fd)
{
	if (IS_NEG(read(fd, champion->comment, ALIGN_4(sizeof(champion->comment)))))
		EXIT_FAIL("Error : can not read comment");
}
