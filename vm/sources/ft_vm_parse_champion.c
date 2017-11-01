/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_champion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:11:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/31 13:26:28 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <fcntl.h>

/*
* brief      		Parse champions from arguments
*
* param option		Options array
* param av			Arguments array
*/

void ft_vm_parse_champion(int option[], char **av)
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
					while (option[current_champ] && (current_champ <= MAX_PLAYERS))
						++current_champ;
					if (current_champ <= MAX_PLAYERS)
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
