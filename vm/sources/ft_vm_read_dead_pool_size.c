/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_dead_pool_size.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:46:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/22 21:31:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/**
 * \fn void 	ft_vm_read_dead_pool_size(t_header *champion, const int fd)
 * \brief Read champions' binaries
 *
 * \param champion
 * \param file descriptor
 * \return None
 */

void		ft_vm_read_dead_pool_size(t_header *champion, const int fd)
{
	if (IS_NEG(read(fd, &champion->prog_size, sizeof(champion->prog_size))))
		EXIT_FAIL("Error : can not read prog_size");
	if (IS_LITTLE_ENDIAN)
		champion->prog_size = ft_endian_convert_uint32(champion->prog_size);
	if (champion->prog_size > CHAMP_MAX_SIZE)
		EXIT_FAIL("Error : the program is too big");
}
