/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:16:28 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 16:14:12 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

int			ft_display_arena(t_vm *vm)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < (MEM_SIZE >> 6))
	{
		j = 0;
		ft_printf("0x%04x : ", i << 6);
		while (j < 64)
		{
			/* Print '00' if stealth mode is ON */
			if (0 != vm->opt.stealth)
				ft_printf("ff ");
			/* Else, print the correct byte */
			else
				ft_printf("%02hhx ", ft_arena_get_int8(vm, (i << 6) + j));
			++j;
		}
		ft_printf("\n");
		++i;
	}
	return (EXIT_FAILURE);
}
