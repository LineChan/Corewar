/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/11/18 19:10:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

 /*
 * brief      		Virtual Machine's main function
 *
 * param ac				Number of arguments
 * param av				Options' array
 */

int				main(int ac, char **av)
{
	int				option[OPTION_MAX];
	unsigned int	nb_champion;
	unsigned char	arena[MEM_SIZE];
	t_dead_pool		dead_pool;
	t_option		*opt;

	opt = ft_vm_parse_option(option, ac, av);
	ft_vm_parse_champion(option, av);
	/* Read each champion's header */
	ft_vm_read_champion(option, &dead_pool, &nb_champion);
	ft_vm_print_stat(&dead_pool, option);
	ft_printf("{green:separator}\n");
	/* Start the battle */
	ft_vm_arena(arena, option, &dead_pool, &nb_champion);
	ft_option_del(&opt);
	return (EXIT_SUCCESS);
}
