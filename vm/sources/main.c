/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2017/10/21 18:23:30 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

int main(int ac, char **av)
{
	int				option[OPTION_MAX];
	t_option	*opt;
	t_header	header;
	//char			vm[MEM_SIZE];

	opt = ft_vm_option(option, ac, av);
	ft_vm_parse_champion(option, av);
	ft_vm_read_champion(option, &header);
	#if 0
	int i = -1;
	while (i++ < 5)
	{
		ft_printf("option[%d] : %d\n", i, option[i]);
		if (option[i])
		{
			ft_printf("test\n");
			int ret;
			ret = read(option[i], &header.magic, sizeof(header.magic));

			ft_printf("read : '%s' ret : %x\n", line, header.magic);
		}
	}
	i = 1;
	while (i <= MAX_PLAYERS)
{
		option[i] ? close(option[i]) : 0;
		++i;
	}
	#endif
	ft_option_del(&opt);
	return (EXIT_SUCCESS);
}
