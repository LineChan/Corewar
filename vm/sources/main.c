/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/10/20 19:13:53 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"
# include <unistd.h>

int main(int ac, char **av)
{
	int				option[6];
	char			line[1000 + 1];
	t_option	*opt;
	//t_vm		vm;

	opt = ft_vm_option(option, ac, av);
	ft_vm_parse_champion(option, av);
	ft_option_del(&opt);
	int i = -1;
	while (i++ < 5)
	{
		if (option[i])
		{
			ft_printf("option[%d] : %d\n", i, option[i]);
			ft_printf("test\n");
			int ret;
			ret = read(option[i], line, 1000);

			ft_printf("read : '%s' ret : %d", line, ret);
		}

	}
	i = 1;
	while (i <= MAX_PLAYERS)
	{
		option[i] ? close(option[i]) : 0;
		++i;
	}
	return (EXIT_SUCCESS);
}
