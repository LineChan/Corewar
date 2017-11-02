/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 21:51:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/02 10:15:47 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      		Set up the virtual machine
*
* param arena		Memory dedicated to the virtual machine
* param option		Options' array
* param dead_pool	Structure gatehering all the champions
* param nb_champion	Champions number
*/

void		ft_vm_arena(unsigned char arena[MEM_SIZE],
	 							int option[],
								t_dead_pool *dead_pool,
								int *nb_champion)
{
	ft_memset(arena, 0, MEM_SIZE);
	ft_vm_arena_upload_champion(arena, option, dead_pool, nb_champion);
	ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
	ft_vm_instr(arena, dead_pool, nb_champion);
	ft_vm_print_arena((void *)arena, MEM_SIZE, 64, dead_pool);
}
