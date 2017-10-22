/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 21:51:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/23 00:13:58 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/**
 * \fn int	main(int ac, char **av)
 * \brief Virtual Machine's main function
 *
 * \param number of arguments
 * \param arguments' list
 * \return 0
 */

void		ft_vm_arena(char arena[MEM_SIZE],
	 							int option[],
								t_dead_pool *dead_pool,
								int *nb_champion)
{
	ft_memset(arena, 0, MEM_SIZE);
	ft_vm_arena_upload_champion(arena, option, dead_pool, nb_champion);

	ft_printf("option[0] : %d\n", option[0]);
	ft_printf("dead_pool->magic : %x\n", dead_pool->champion1.magic);
	ft_printf("nb_champion : %d\n", *nb_champion);
}
