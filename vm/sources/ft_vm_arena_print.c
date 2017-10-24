/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:42:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/24 19:18:35 by mvillemi         ###   ########.fr       */
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

void 		ft_vm_arena_print_pc(void)
{
		ft_fprintf(2, "champion1 : %02hhx\n", *PC->champion1);
		ft_fprintf(2, "champion2 : %02hhx\n", *PC->champion2);
		ft_fprintf(2, "champion3 : %02hhx\n", *PC->champion3);
		ft_fprintf(2, "champion4 : %02hhx\n", *PC->champion4);
}
