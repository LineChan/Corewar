/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_arena_upload_champion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:40:26 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/23 00:13:56 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"
# define STEP (MEM_SIZE / *nb_champion)

/**
 * \fn void ft_vm_arena_upload_champion(char arena[], int option[], t_dead_pool *dead_pool, int *nb_champion)
 * \brief Upload champions on the arena
 *
 * \param arena
 * \param option
 * \param dead_pool
 * \param champions' number
 * \return None
 */


void 		ft_vm_arena_upload_routine(const int fd,
										char arena[],
										t_header *champion,
										const int index)
{
	char	tmp[CHAMP_MAX_SIZE];

	ft_printf("upload routine : %d\n", champion->prog_size);
	ft_memset(tmp, 0, CHAMP_MAX_SIZE);
	read(fd, &arena[index], champion->prog_size);
	//ft_printf("tmp : '%s'\n", tmp);
	//ft_strncpy(arena, tmp, champion->prog_size);
	ft_printf("index : %d\n", index);

}

void		ft_vm_arena_upload_champion(char arena[],
										int option[],
										t_dead_pool *dead_pool,
										int *nb_champion)
{
	int		index = 0;
	//option[1] ? ft_printf
	if (option[1])
	{
		ft_vm_arena_upload_routine(option[1], arena,
									&dead_pool->champion1, index);
		index += STEP;
	}
	if (option[2])
	{
		ft_vm_arena_upload_routine(option[2], arena,
									&dead_pool->champion2, index);
		index += STEP;
	}
	if (option[3])
	{
		ft_vm_arena_upload_routine(option[3], arena,
									&dead_pool->champion3, index);
		index += STEP;
	}
	if (option[4])
	{
		ft_vm_arena_upload_routine(option[4], arena,
									&dead_pool->champion4, index);
		index += STEP;
	}

	ft_vm_arena_print(arena);
	ft_printf("STEP : %d\n", STEP);
	ft_printf("champion1.name : '%s'\n", dead_pool->champion1.prog_name);
	ft_printf("nb_champion : %d\n", *nb_champion);
}
