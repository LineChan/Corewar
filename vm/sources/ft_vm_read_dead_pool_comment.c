/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_dead_pool_comment.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:27:35 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/22 21:31:50 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/**
 * \fn  void ft_vm_read_dead_pool_comment(t_header *champion, const int fd)
 * \brief Read champion's comment
 *
 * \param champion
 * \param file descriptor
 * \return None
 */

void			ft_vm_read_dead_pool_comment(t_header *champion, const int fd)
{
	if (IS_NEG(read(fd, champion->comment, ALIGN_4(sizeof(champion->comment)))))
		EXIT_FAIL("Error : can not read comment");
}
