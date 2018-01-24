/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:16:28 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/24 14:44:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

int			ft_display_arena(t_vm *vm)
{
	size_t		i;

	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		ft_printf("%02hhx ", vm->arena[0][i++]);
		if (0 == (i & 63))
			ft_printf("\n");
		if (0 == (i & 63) && (0 != i % MEM_SIZE))
			ft_printf("0x%04x : ", i);
	}
	return (EXIT_FAILURE);
}
#if 0
void			ft_display_arena(void const *data,
								size_t msize,
								size_t nb_byte,
								t_vm *vm)
{
	unsigned char		*p;
	size_t				i;

	i = 0;
	p = (unsigned char *)data;
	while (i < msize)
	{
		if (!(i % nb_byte))
		{
			ft_printf("0x%04x : ", p - vm->arena[0]);
		}
		ft_printf("%02hhx ", *p);
		++p;
		++i;
		if (!(i % nb_byte))
			ft_printf("\n");
	}
}
#endif
