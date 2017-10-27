/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:12:04 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/27 16:23:08 by mvillemi         ###   ########.fr       */
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

void	ft_vm_print_arena(void const *data, size_t msize, size_t nb_byte)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)data;
	while (i < msize)
	{
		if (0 != *p)
			ft_fprintf(2, "{green:%02hhx} ", *p);
		else
			ft_fprintf(2, "{bblack:00} ");
		++p;
		++i;
		if (0 == (i % nb_byte))
			ft_printf("\n");
	}
	if (i % nb_byte)
		ft_printf("\n");
}

void 		ft_vm_print_pc(void)
{
	(PC_1) ? ft_fprintf(2, "champion1 : %02hhx\n", *PC_1) : 0;
	(PC_2) ? ft_fprintf(2, "champion2 : %02hhx\n", *PC_2) : 0;
	(PC_3) ? ft_fprintf(2, "champion3 : %02hhx\n", *PC_3) : 0;
	(PC_4) ? ft_fprintf(2, "champion4 : %02hhx\n", *PC_4) : 0;
}

void		ft_vm_print_instr(t_list *it)
{
	ft_fprintf(2, "instr : %s\n", C_INSTR(it)->op->name);
}
