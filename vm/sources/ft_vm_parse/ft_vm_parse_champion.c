/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_champion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:39:50 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/21 12:01:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ctype.h"

/*
* brief           Parse champions from arguments
*
* param option    t_dead_pool struct for the game
* param ac        Number of arguments
* param av        Arguments list
*/

void 			ft_vm_parse_champion(t_dead_pool *dead_pool, int ac, char **av)
{
	unsigned int	current_i;
	unsigned int	n;
	unsigned int	fd_tmp[4];
	char	*tmp;

	(void)dead_pool;
	/* Go through the list of arguments */
	current_i = 0;
	while (ac)
	{
		ft_printf("champion : %s\n", *av + ft_strlen(*av) - 4);
		/* If a .cor file is found */
		if (*(int *)".cor" == *(int *)(*av + ft_strlen(*av) - 4))
		{
			/* Look the previous argument for the -n=nb or -n nb option*/
			tmp = *(av - 1);
			if (!ft_strncmp("-n=", tmp, 3))
			{
				n = ft_atoi(*av + 3);
				if ((n < 1) || (n > MAX_PLAYERS) || dead_pool->option.champ[n])
					EXIT_FAIL("Error : The player number is invalid");
				dead_pool->option.fd[n] = open(*av, O_RDONLY, 0666);
			}
			if (ft_isdigit(*tmp))
			{
				if (ft_str*(av - 2))
			}
		}
		++av;
		--ac;
	}
}
