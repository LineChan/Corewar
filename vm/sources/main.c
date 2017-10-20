/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/10/20 17:23:54 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

int main(int ac, char **av)
{
	int				option[6];
	t_option	*opt;
	//t_vm		vm;

	opt = ft_vm_option(option, ac, av);
	ft_vm_parse_champion(option, ac, av);
	ft_option_del(&opt);
	int i = -1;
	while (i++ < 5)
		ft_printf("option[%d] : %d\n", i, option[i]);
	return (EXIT_SUCCESS);
}
