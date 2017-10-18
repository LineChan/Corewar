/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/10/19 01:42:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

int main(int ac, char **av)
{
	int				option[3];
	t_option	*opt;

	opt = ft_option(option, ac, av);
	ft_printf("dump option : '%s'\n", ft_option_find(opt, "-dump"));
	ft_printf("dump : %d\n", option[0]);
	ft_printf("n : %d\n", option[1]);
	ft_option_del(&opt);
	return (EXIT_SUCCESS);
}
