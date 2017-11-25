/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_print_arena.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 13:22:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/25 14:03:22 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_vm_print_arena(void const *data,
									size_t msize,
									size_t nb_byte,
									t_vm *vm)
{
	unsigned char	*p;
	size_t			i;
	t_list			*it;

	i = 0;
	p = (unsigned char *)data;
	while (i < msize)
	{
		if (!ft_list_is_empty(&vm->process_head))
		{
			it = vm->process_head.next;
			while (it != &vm->process_head)
			{
				if (p == C_PROCESS(it)->pc)
				{
					ft_fprintf(2, "{red:%02hhx} ", *p);
					++p;
					++i;
				}
				it = it->next;
			}
		}
		if (0 != *p)
		{
			ft_fprintf(2, "{green:%02hhx} ", *p);
			++p;
			++i;
		}
		else
		{
			ft_fprintf(2, "{bblack:00} ");
			++p;
			++i;
		}
		if (0 == (i % nb_byte))
			ft_fprintf(2,"\n");
	}
	if (i % nb_byte)
		ft_fprintf(2,"\n");

}
