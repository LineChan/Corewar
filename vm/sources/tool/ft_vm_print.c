/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:12:04 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 23:08:40 by mvillemi         ###   ########.fr       */
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

void 		ft_vm_print_pc(t_dead_pool *dead_pool)
{
	dead_pool->champ[0].pc ? ft_fprintf(2, "champion1 : %02hhx\n", *dead_pool->champ[0].pc) : 0;
	dead_pool->champ[1].pc ? ft_fprintf(2, "champion2 : %02hhx\n", *dead_pool->champ[1].pc) : 0;
	dead_pool->champ[2].pc ? ft_fprintf(2, "champion3 : %02hhx\n", *dead_pool->champ[2].pc) : 0;
	dead_pool->champ[3].pc ? ft_fprintf(2, "champion4 : %02hhx\n", *dead_pool->champ[3].pc) : 0;
}

void 		ft_vm_print_reg(t_champion *champ)
{
	ft_fprintf(2, "reg[0] : %d\n", champ->reg[0]);
	ft_fprintf(2, "reg[1] : %d\n", champ->reg[1]);
	ft_fprintf(2, "reg[2] : %d\n", champ->reg[2]);
	ft_fprintf(2, "reg[3] : %d\n", champ->reg[3]);
	ft_fprintf(2, "reg[4] : %d\n", champ->reg[4]);
	ft_fprintf(2, "reg[5] : %d\n", champ->reg[5]);
	ft_fprintf(2, "reg[6] : %d\n", champ->reg[6]);
	ft_fprintf(2, "reg[7] : %d\n", champ->reg[7]);
	ft_fprintf(2, "reg[8] : %d\n", champ->reg[8]);
	ft_fprintf(2, "reg[9] : %d\n", champ->reg[9]);
	ft_fprintf(2, "reg[10] : %d\n", champ->reg[10]);
	ft_fprintf(2, "reg[11] : %d\n", champ->reg[11]);
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
