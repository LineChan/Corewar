/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/11/22 18:39:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

/*
* brief      			CoreWar's main function
*
* param ac				Number of arguments
* param av				Arguments' array
*/

int				main(int ac, char **av)
{
	unsigned int	nb_champion;
	unsigned char	arena[2][MEM_SIZE];
	t_dead_pool		dead_pool;

	(void)arena;
	if (ac < 2)
		return (EXIT_FAILURE);
	++av;
	ft_memset((void *)&dead_pool, '\0', sizeof(t_dead_pool));
	/* Parse all options and champions */
	ft_vm_parse(&dead_pool, av);
	/* Read each champion's header */
	ft_vm_read_header(&dead_pool, &nb_champion);
	/* Print introduction to the battle */
	ft_vm_print_intro(&dead_pool);
	/* Handle the battle */
	ft_vm_arena(arena, &dead_pool, &nb_champion);
	return (EXIT_SUCCESS);
}
