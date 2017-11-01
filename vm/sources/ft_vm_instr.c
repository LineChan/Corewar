/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:04:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/01 14:32:21 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

// TODO:presentation

void			ft_vm_instr(unsigned char arena[],
							t_dead_pool *dead_pool,
							int *nb_champion)
{
	(void)*nb_champion;
	while (1)
	{
		if (ft_vm_instr_read(arena, dead_pool, *nb_champion) == EXIT_SUCCESS)
			break ;
		ft_vm_instr_exec(arena, dead_pool);

	}
}
