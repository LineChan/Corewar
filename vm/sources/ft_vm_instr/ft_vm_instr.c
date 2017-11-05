/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:04:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/05 21:44:43 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO: presentation

#include <libc.h>

void			ft_vm_instr(unsigned char arena[], t_dead_pool *dead_pool,
							unsigned const int nb_champion, unsigned int current_cyle)
{
	int i;

	i = 0;
	while (i < 1)
	{
		if (ft_vm_instr_read(arena, dead_pool, nb_champion, current_cyle) == EXIT_SUCCESS)
		{
			break ;

		}
		ft_printf("end of turn\n");
		++i;
		getchar();
	}
}
