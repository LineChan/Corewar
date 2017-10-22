/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_dead_pool_magic.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 16:48:18 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/22 19:16:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/**
 * \fn void ft_vm_read_dead_pool_magic(t_header *champion, const int fd)
 * \brief Check magic numbers
 *
 * \param champion
 * \param file descriptor
 * \return None
 */

void ft_vm_read_dead_pool_magic(t_header *champion,
							   const int fd)
{
   if ((IS_NEG(read(fd, &champion->magic, sizeof(champion->magic)))))
	 EXIT_FAIL("Error : can not read the magic number");
   if (IS_LITTLE_ENDIAN)
   {
	   champion->magic = ft_endian_convert_uint32(champion->magic);
	   if ((champion->magic ^ COREWAR_EXEC_MAGIC))
		   EXIT_FAIL("Error : wrong magic number");
   }
}
