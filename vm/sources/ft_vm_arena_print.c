/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:42:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/24 00:08:21 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

 /*
 * brief      		Memory dump
 *
 * param data		Pointer to the memory region we want to dump
 * param msize		Size of the data
 * param nb_byte	Bytes per line
 */

void	ft_vm_arena_print(void const *data, size_t msize, size_t nb_byte)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)data;
	while (i < msize)
	{
		if (0 != *p)
			ft_printf("{green:%02hhx} ", *p);
		else
			ft_printf("{bblack:00} ");
		++p;
		++i;
		if (0 == (i % nb_byte))
			ft_printf("\n");
	}
	if (i % nb_byte)
		ft_printf("\n");
}
