/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_champion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:11:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/20 17:29:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <fcntl.h>

void ft_vm_parse_champion(int option[6], int ac, char **av)
{
	int		i;
	int		given_champ;
	int		current_champ;

	i = 0;
	current_champ = 1;
	++ac;
	while (av[i])
	{
		if (!ft_strncmp(av[i], "-c", 2))
		{
			++i;
			if (!ft_strncmp(av[i], "-n", 2))
			{

				++i;
				given_champ = ft_atoi(av[i]);
				option[given_champ] = open(av[i + 1], O_RDONLY, 0666);
				if (IS_NEG(option[given_champ]))
					EXIT_FAIL("Error : cannot read the champion");
				++i;
			}
			else
			{
				if (!option[current_champ])
				{
					option[current_champ] = open(av[i], O_RDONLY, 0666);
					ft_printf("{red:SEGFAULT}\n");
				}
				else
				{
					while (option[current_champ] && (current_champ < 5))
						++current_champ;
					if (current_champ < 5)
					{
						option[current_champ] = open(av[i], O_RDONLY, 0666);
						if (IS_NEG(option[current_champ]))
							EXIT_FAIL("Error : champion out of range");
					}
					else
						EXIT_FAIL("Error : champion out of range");
					ft_printf("{red:SEGFAULT 2}\n");
				}
			}
		}
		++i;
	}
}
