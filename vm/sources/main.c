/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/11/22 01:03:30 by mvillemi         ###   ########.fr       */
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
	unsigned int	nb_champion;
	unsigned char	arena[MEM_SIZE];
	t_dead_pool		dead_pool;

	if (ac < 2)
		return (EXIT_FAILURE);
	++av;
	ft_memset((void *)&dead_pool, '\0', sizeof(t_dead_pool));
	/* Parse all options and champions */
	ft_vm_parse(&dead_pool, av);
	/* Read each champion's header */
	ft_vm_read_header(&dead_pool, &nb_champion);
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
