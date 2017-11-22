/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:12:04 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/22 14:28:38 by mvillemi         ###   ########.fr       */
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
		if ((p == dead_pool->champ[0].pc) || (p == dead_pool->champ[1].pc)
			|| (p == dead_pool->champ[2].pc) || (p == dead_pool->champ[2].pc))
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

void			ft_vm_print_intro(t_dead_pool *dead_pool)
{
	ft_printf("Welcome to {yellow:Corewar} !\nList of champions :\n");
	dead_pool->idx ^= dead_pool->idx;
	while (dead_pool->idx < MAX_PLAYERS)
	{
		if (dead_pool->option.fd[dead_pool->idx])
		{
			ft_printf("* Player {green:%d}, %d bytes, {yellow:%s} (%s)\n",
				dead_pool->idx + 1,
				dead_pool->champ[dead_pool->idx].header.prog_size,
				dead_pool->champ[dead_pool->idx].header.prog_name,
				dead_pool->champ[dead_pool->idx].header.comment);
		}
		++dead_pool->idx;
	}
}

#if 1
static void 	ft_vm_print_name(t_list *src)
{
	ft_printf("--> '%s'\n", C_PROCESS(src)->process.header.prog_name);
}
#endif

void			ft_vm_print_process(t_dead_pool *dead_pool)
{
	ft_list_apply(&dead_pool->champ[dead_pool->idx].process_head, &ft_vm_print_name);
}
