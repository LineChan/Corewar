/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/10/22 19:17:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

void			ft_print_stats(int option[], t_dead_pool *dead_pool)
{
	if (option[1])
	{
		ft_printf("chamion1\n");
		ft_printf("magic : %x\n", dead_pool->champion1.magic);
		ft_printf("name : '%s'\n", dead_pool->champion1.prog_name);
		ft_printf("size : '%zu'\n", dead_pool->champion1.prog_size);
		ft_printf("comment : '%s'\n", dead_pool->champion1.comment);
	}
	if (option[2])
	{
		ft_printf("chamion2\n");
		ft_printf("magic : %x\n", dead_pool->champion2.magic);
		ft_printf("name : '%s'\n", dead_pool->champion2.prog_name);
		ft_printf("size : '%zu'\n", dead_pool->champion2.prog_size);
		ft_printf("comment : '%s'\n", dead_pool->champion2.comment);
	}
	if (option[3])
	{
		ft_printf("chamion3\n");
		ft_printf("magic : %x\n", dead_pool->champion3.magic);
		ft_printf("name : '%s'\n", dead_pool->champion3.prog_name);
		ft_printf("size : '%zu'\n", dead_pool->champion3.prog_size);
		ft_printf("comment : '%s'\n", dead_pool->champion3.comment);
	}
	if (option[4])
	{
		ft_printf("chamion4\n");
		ft_printf("magic : %x\n", dead_pool->champion4.magic);
		ft_printf("name : '%s'\n", dead_pool->champion4.prog_name);
		ft_printf("size : '%zu'\n", dead_pool->champion4.prog_size);
		ft_printf("comment : '%s'\n", dead_pool->champion4.comment);
	}
}
int				main(int ac, char **av)
{
	int					option[OPTION_MAX];
	t_dead_pool			dead_pool;
	t_option			*opt;
	//char			vm[MEM_SIZE];

	opt = ft_vm_parse_option(option, ac, av);
	ft_vm_parse_champion(option, av);
	ft_vm_read_champion(option, &dead_pool);
	ft_print_stats(option, &dead_pool);
	ft_option_del(&opt);
	return (EXIT_SUCCESS);
}
