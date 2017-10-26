/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/10/26 16:33:38 by mvillemi         ###   ########.fr       */
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
		ft_printf("champion1\n");
		ft_printf("magic : %x\n", dead_pool->champion1.magic);
		ft_printf("name : '%s'\n", dead_pool->champion1.prog_name);
		ft_printf("size : '%d'\n", dead_pool->champion1.prog_size);
		ft_printf("comment : '%s'\n", dead_pool->champion1.comment);
	}
	if (option[2])
	{
		ft_printf("champion2\n");
		ft_printf("magic : %x\n", dead_pool->champion2.magic);
		ft_printf("name : '%s'\n", dead_pool->champion2.prog_name);
		ft_printf("size : '%d'\n", dead_pool->champion2.prog_size);
		ft_printf("comment : '%s'\n", dead_pool->champion2.comment);
	}
	if (option[3])
	{
		ft_printf("champion3\n");
		ft_printf("magic : %x\n", dead_pool->champion3.magic);
		ft_printf("name : '%s'\n", dead_pool->champion3.prog_name);
		ft_printf("size : '%d'\n", dead_pool->champion3.prog_size);
		ft_printf("comment : '%s'\n", dead_pool->champion3.comment);
	}
	if (option[4])
	{
		ft_printf("champion4\n");
		ft_printf("magic : %x\n", dead_pool->champion4.magic);
		ft_printf("name : '%s'\n", dead_pool->champion4.prog_name);
		ft_printf("size : '%d'\n", dead_pool->champion4.prog_size);
		ft_printf("comment : '%s'\n", dead_pool->champion4.comment);
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
	ft_vm_arena(arena, option, &dead_pool, &nb_champion);
	ft_option_del(&opt);
	//return (EXIT_SUCCESS);
	option[1] ? ft_del_singl_champ(&CHAMP_1->champion_head) : 0;
	option[2] ? ft_del_singl_champ(&CHAMP_2->champion_head) : 0;
	option[3] ? ft_del_singl_champ(&CHAMP_3->champion_head) : 0;
	option[4] ? ft_del_singl_champ(&CHAMP_4->champion_head) : 0;
	return (EXIT_SUCCESS);
}
