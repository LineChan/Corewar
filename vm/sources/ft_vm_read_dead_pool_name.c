/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_dead_pool_name.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 14:59:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/22 19:16:51 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/**
 * \fn void 	ft_vm_read_dead_pool_name(int option[], t_dead_pool *dead_pool)
 * \brief Read champions' binaries
 *
 * \param champion
 * \param file descriptor
 * \return None
 */

void			ft_vm_read_dead_pool_name(t_header *champion, const int fd)
{
	if ((IS_NEG(read(fd, &champion->prog_name, PROG_NAME_LENGTH))))
		EXIT_FAIL("Error : can not read prog_name");
}
