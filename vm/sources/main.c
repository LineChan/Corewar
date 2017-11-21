/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/11/21 19:53:38 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

 /*
 * brief      		Virtual Machine's main function
 *
 * param ac				Number of arguments
 * param av				Arguments' array
 */

int				main(int ac, char **av)
{
	//int				option[OPTION_MAX];
	unsigned int	nb_champion;
	unsigned char	arena[MEM_SIZE];
	t_dead_pool		dead_pool;
	//t_option		*opt;

	if (ac < 2)
		return (EXIT_FAILURE);
	--ac;
	++av;
	//MEMSET DEAD_POOL
	ft_vm_parse(&dead_pool, av);
	(void)nb_champion;
	(void)arena;
	(void)dead_pool;
	#if 0
	opt = ft_vm_parse_option(&dead_pool, ac, av);
	ft_vm_parse_champion(&dead_pool, av);
	/* Read each champion's header */
	ft_vm_read_champion(option, &dead_pool, &nb_champion);
	ft_vm_print_stat(&dead_pool, option);
	ft_printf("{green:separator}\n");
	/* Start the battle */
	ft_vm_arena(arena, option, &dead_pool, &nb_champion);
	ft_option_del(&opt);
	#endif
	return (EXIT_SUCCESS);
}
