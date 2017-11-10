/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/11/10 15:53:27 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

 /*
 * brief      		Virtual Machine's main function
 *
 * param ac				Number of arguments
 * param av				Options' array
 */


void			ft_print_stats(int option[], t_dead_pool *dead_pool)
{
	if (option[1])
	{
		ft_fprintf(2, "header1\n");
		ft_fprintf(2, "magic : %x\n", dead_pool->champion1.header.magic);
		ft_fprintf(2, "name : '%s'\n", dead_pool->champion1.header.prog_name);
		ft_fprintf(2, "size : '%d'\n", dead_pool->champion1.header.prog_size);
		ft_fprintf(2, "comment : '%s'\n", dead_pool->champion1.header.comment);
	}
	if (option[2])
	{
		ft_fprintf(2, "header2\n");
		ft_fprintf(2, "magic : %x\n", dead_pool->champion2.header.magic);
		ft_fprintf(2, "name : '%s'\n", dead_pool->champion2.header.prog_name);
		ft_fprintf(2, "size : '%d'\n", dead_pool->champion2.header.prog_size);
		ft_fprintf(2, "comment : '%s'\n", dead_pool->champion2.header.comment);
	}
	if (option[3])
	{
		ft_fprintf(2, "header3\n");
		ft_fprintf(2, "magic : %x\n", dead_pool->champion3.header.magic);
		ft_fprintf(2, "name : '%s'\n", dead_pool->champion3.header.prog_name);
		ft_fprintf(2, "size : '%d'\n", dead_pool->champion3.header.prog_size);
		ft_fprintf(2, "comment : '%s'\n", dead_pool->champion3.header.comment);
	}
	if (option[4])
	{
		ft_fprintf(2, "header4\n");
		ft_fprintf(2, "magic : %x\n", dead_pool->champion4.header.magic);
		ft_fprintf(2, "name : '%s'\n", dead_pool->champion4.header.prog_name);
		ft_fprintf(2, "size : '%d'\n", dead_pool->champion4.header.prog_size);
		ft_fprintf(2, "comment : '%s'\n", dead_pool->champion4.header.comment);
	}
}

int				main(int ac, char **av)
{
	int				option[OPTION_MAX];
	int				nb_champion;
	unsigned char	arena[MEM_SIZE];
	t_dead_pool		dead_pool;
	t_option		*opt;

	opt = ft_vm_parse_option(option, ac, av);
	ft_vm_parse_champion(option, av);
	ft_vm_read_champion(option, &dead_pool, &nb_champion);
	if (DEBUG_MODE)
		ft_print_stats(option, &dead_pool);
	ft_vm_arena(arena, option, &dead_pool, &nb_champion);
	ft_option_del(&opt);
	return (EXIT_SUCCESS);
}
