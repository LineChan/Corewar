/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_champion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:51:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/03 17:04:31 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_string.h"
#include "macro.h"
#include <fcntl.h>

static void 	ft_vm_champion_repartition(t_vm *vm,
												unsigned int fd[4],
												const int current_i)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	/* Champions with no specific number are inserted at empty spots in the */
	/* champions' array */
	while (i < current_i)
	{
		while (vm->fd[j])
			++j;
		vm->fd[j] = fd[i];
		++i;
	}
}

void 			ft_vm_parse_champion(t_vm *vm, char **av)
{
	static unsigned int			fd[4] = {0};
	unsigned int				n;
	unsigned int				current_i;
	unsigned int				champion_found;

	/* Go trough the list of arguments */
	champion_found = 0;
	current_i = 0;
	while (*av)
	{
		/* If a specific number is given for a champion, its File Descriptor */
		/* is stored in the options structure. Otherwise it's stored in a */
		/* temporary array and will be distributed at the end of the parsing */
		if (!ft_strncmp("-n", *av, 2))
		{
			if (*(*av + 2) == '=')
			{
				/* -n=nb champion.cor */
				n = ft_atoi(*av + 3);
			}
			else if (*(*av + 2) == '\0')
			{
				/* -n nb champion.cor */
				++av;
				n = ft_atoi(*av);
			}
			/* Check if the number is valid and if it hasn't been given yet */
			if ((n < 1) || (n > MAX_PLAYERS) || vm->fd[n - 1])
				EXIT_FAIL("Error : The player number is invalid");
			++av;
			/* Check the extension of a champion's file (.cor) */
			if (*(int *)".cor" != *(int *)(*av + ft_strlen(*av) - 4))
				EXIT_FAIL("Error : not a champion's file (.cor)");
			/* Exit if the file can't be opened */
			if (IS_NEG((vm->fd[n - 1] = open(*av, O_RDONLY, 0666))))
				EXIT_FAIL("Error : Cannot read the champion");
			++champion_found;
		}
		else if (*(int *)".cor" == *(int *)(*av + ft_strlen(*av) - 4))
		{
			fd[current_i++] = open(*av, O_RDONLY, 0666);
			if ((current_i + champion_found) >= MAX_PLAYERS)
				EXIT_FAIL("Error : Too many champions want to fight !");
		}
		++av;
	}
	/* Distribute all champions with no specific number */
	current_i ? ft_vm_champion_repartition(vm, fd, current_i) : 0;
}
