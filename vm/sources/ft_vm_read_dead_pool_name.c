/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_dead_pool_name.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 14:59:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/24 00:37:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      		Read champion's name from header
*
* param champion	Champion's structure
* param fd			File Descriptor
*/

void	ft_vm_read_dead_pool_name(t_header *champion, const int fd)
{
	if (IS_NEG(read(fd, champion->prog_name, ALIGN_4(sizeof(champion->prog_name)))))
		EXIT_FAIL("Error : can not read prog_name");
}
