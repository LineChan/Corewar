/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:12:04 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/02 11:02:54 by mvillemi         ###   ########.fr       */
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

void	ft_vm_print_arena(void const *data,
							size_t msize,
							size_t nb_byte,
							t_dead_pool *dead_pool)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)data;
	while (i < msize)
	{
		if ((p == dead_pool->champion1.pc) || (p == dead_pool->champion2.pc)
			|| (p == dead_pool->champion3.pc) || (p == dead_pool->champion4.pc))
		{
			ft_fprintf(2, "{red:%02hhx} ", *p);
		}
		else if (0 != *p)
		{
			ft_fprintf(2, "{green:%02hhx} ", *p);
		}
		else
			ft_fprintf(2, "{bblack:00} ");
		++p;
		++i;
		if (0 == (i % nb_byte))
			ft_fprintf(2,"\n");
	}
	if (i % nb_byte)
		ft_fprintf(2,"\n");
}

void 		ft_vm_print_pc(t_dead_pool *dead_pool)
{
	dead_pool->champion1.pc ? ft_fprintf(2, "champion1 : %02hhx\n", *dead_pool->champion1.pc) : 0;
	dead_pool->champion2.pc ? ft_fprintf(2, "champion2 : %02hhx\n", *dead_pool->champion1.pc) : 0;
	dead_pool->champion3.pc ? ft_fprintf(2, "champion3 : %02hhx\n", *dead_pool->champion1.pc) : 0;
	dead_pool->champion4.pc ? ft_fprintf(2, "champion4 : %02hhx\n", *dead_pool->champion1.pc) : 0;
}
