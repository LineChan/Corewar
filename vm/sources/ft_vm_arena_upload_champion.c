/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_upload_champion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:40:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/04 15:48:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      		Upload champions in the arena
*
* param fd			File Descriptor
* param arena		Memory dedicated to the virtual machine
* param dead_pool	Structure gathering all the champions
* param nb_champion	Champions' number
*/

void 		ft_vm_arena_up_routine(const int fd,
										unsigned char arena[],
										t_champion *champ,
										int index)
{
	read(fd, &arena[index], champ->header.prog_size);
	close(fd);
}

void		ft_vm_arena_upload_champion(unsigned char arena[],
										int option[],
										t_dead_pool *dead_pool,
										int *nb_champion)
{
	int		index;
	int		step;

	!*nb_champion ? EXIT_FAIL("Error : no champion") : 0;
	step = MEM_SIZE / *nb_champion;
	index = 0;
	if (option[1])
	{
		ft_vm_arena_up_routine(option[1], arena, &dead_pool->champion1, index);
		dead_pool->champion1.pc = &arena[index];
		dead_pool->champion1.reg[0] = 1;
		index += step;
	}
	if (option[2])
	{
		ft_vm_arena_up_routine(option[2], arena, &dead_pool->champion2, index);
		dead_pool->champion2.pc = &arena[index];
		dead_pool->champion2.reg[0] = 2;
		index += step;
	}
	if (option[3])
	{
		ft_vm_arena_up_routine(option[3], arena, &dead_pool->champion3, index);
		dead_pool->champion3.pc = &arena[index];
		dead_pool->champion3.reg[0] = 3;
		index += step;
	}
	if (option[4])
	{
		ft_vm_arena_up_routine(option[4], arena, &dead_pool->champion4, index);
		dead_pool->champion4.pc = &arena[index];
		dead_pool->champion4.reg[0] = 4;
	}
}