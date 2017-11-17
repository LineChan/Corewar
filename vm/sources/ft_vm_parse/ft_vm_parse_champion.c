/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_champion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:11:05 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 11:04:26 by mvillemi         ###   ########.fr       */
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
// TODO : to be checked : you cannot have 2 champions with the same number

void ft_vm_parse_champion(int option[], char **av)
{
	int		i;
	int		given_champ;
	int		current_champ;

	i = 0;
	current_champ = 1;
	while (av[i])
	{
		/* Find a champion's option */
		if (!ft_strncmp(av[i], "-c", 2))
		{
			++i;
			!av[i] ? EXIT_FAIL("Error : near -c") : 0;
			/* If a champion's number is found*/
			if (!ft_strncmp(av[i], "-n", 2))
			{
				++i;
				!av[i] ? EXIT_FAIL("Error : near -n") : 0;
				given_champ = ft_atoi(av[i]);
				/* if a number is found, store the File Descriptor in the option array */
				option[given_champ] = open(av[i + 1], O_RDONLY, 0666);
				if (IS_NEG(option[given_champ]))
					EXIT_FAIL("Error : cannot read the champion");
				++i;
			}
			else
			{
				/* If the array at current_champ if available */
				if (!option[current_champ])
				{
					/* Store the File Descriptor in the option array */
					if (av[i])
						option[current_champ] = open(av[i], O_RDONLY, 0666);
					else
						EXIT_FAIL("Error : near -c");
				}
				else
				{
					/* Find an avaible player for the champion */
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
