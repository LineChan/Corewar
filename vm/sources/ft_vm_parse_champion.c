/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_champion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:11:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/20 19:13:56 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <fcntl.h>

/*
** Open a champion file and attribute an order in the queue list
** 1st parameter : option
** 2nd parameter : list of arguments
*/
void ft_vm_parse_champion(int option[6], char **av)
{
	int		i;
	int		given_champ;
	int		current_champ;

	i = 0;
	current_champ = 1;
	while (av[i])
	{
		if (!ft_strncmp(av[i], "-c", 2))
		{
			++i;
			!av[i] ? EXIT_FAIL("Error : near -c") : 0;
			if (!ft_strncmp(av[i], "-n", 2))
			{
				++i;
				!av[i] ? EXIT_FAIL("Error : near -n") : 0;
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
					if (av[i])
						option[current_champ] = open(av[i], O_RDONLY, 0666);
					else
						EXIT_FAIL("Error : near -c");
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
				}
			}
		}
		++i;
	}
}
