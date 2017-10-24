/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_dead_pool_magic.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 16:48:18 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/24 00:37:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
* brief      		Read the Magic Number from header
*
* param champion	Champion's structure
* param fd			File Descriptor
*/

void  ft_vm_read_dead_pool_magic(t_header *champion, const int fd)
{
   	if (IS_NEG(read(fd, &champion->magic, sizeof(champion->magic))))
		EXIT_FAIL("Error : can not read the magic number");
   	if (IS_LITTLE_ENDIAN)
	   	champion->magic = ft_endian_convert_uint32(champion->magic);
    if (champion->magic ^ COREWAR_EXEC_MAGIC)
		EXIT_FAIL("Error : wrong magic number");
}
