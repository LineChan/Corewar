/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_arena.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:54:53 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/13 17:38:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_vm_display_arena(void const *data,
									size_t msize,
									size_t nb_byte,
									t_vm *vm)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)data;
	while (i < msize)
	{
		if (!(i % nb_byte))
		{
			ft_printf("0x%04x : ", p - vm->arena[0]);
		}
		ft_printf("%02hhx ",*p);
		++p;
		++i;
		if (!(i % nb_byte))
			ft_printf("\n");
	}
}
