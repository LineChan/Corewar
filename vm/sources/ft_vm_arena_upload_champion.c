/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_upload_champion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:40:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/24 00:16:42 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      		Upload champions in the arena
*
* param fd			File Descriptor
* param arena		Memory dedicated to the virtual machine
* param dead_pool	Structure gatehering all the champions
* param nb_champion	Champions' number
*/

void 		ft_vm_arena_up_routine(const int fd,
										char arena[],
										t_header *champion,
										int index)
{
	char	tmp[CHAMP_MAX_SIZE];

	ft_memset(tmp, 0, CHAMP_MAX_SIZE);
	read(fd, &arena[index], champion->prog_size);
}

void		ft_vm_arena_upload_champion(char arena[],
										int option[],
										t_dead_pool *dead_pool,
										int *nb_champion)
{
	int		index = 0;
	int		step;

	if (!*nb_champion)
		EXIT_FAIL("Error : no champion");
	step = MEM_SIZE / *nb_champion;
	if (option[1])
	{
		ft_vm_arena_up_routine(option[1], arena, &dead_pool->champion1, index);
		index += step;
	}
	if (option[2])
	{
		ft_vm_arena_up_routine(option[2], arena, &dead_pool->champion2, index);
		index += step;
	}
	if (option[3])
	{
		ft_vm_arena_up_routine(option[3], arena, &dead_pool->champion3, index);
		index += step;
	}
	if (option[4])
	{
		ft_vm_arena_up_routine(option[4], arena, &dead_pool->champion4, index);
		index += step;
	}
	ft_vm_arena_print((void *)arena, MEM_SIZE, 64);
}
