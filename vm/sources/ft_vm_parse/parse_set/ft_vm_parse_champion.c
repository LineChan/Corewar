/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_champion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:51:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/10 20:27:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_string.h"
#include "macro.h"
#include <fcntl.h>

#if 1
void 	ft_vm_parse_champion_repartition(t_vm *vm)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	/* Champions with no specific number are inserted at empty spots in the */
	/* champions' array */
	while (i < MAX_PLAYERS)
	{
		while (vm->fd[j])
		{
			++j;
		}
		vm->fd[j] = vm->fd_tmp[i];
		++i;
	}
	i = 0;
	while (i < MAX_PLAYERS)
	{
		ft_printf("print fd[%d] = %d\n", i, vm->fd[i]);
		++i;
	}
}
#endif

#if 0
static void		ft_vm_check_champion_nb(t_vm const *vm,
										const int current_i,
										int all_champions_found)
{
	int		i;
	int		player_set;

	if (current_i == MAX_PLAYERS)
		ft_exit("Too many champions want to fight");
	i = 0;
	player_set = 0;
	while (i < MAX_PLAYERS)
	{
		if (vm->fd[i])
			++player_set;
		++i;
	}
}
#endif

void 			ft_vm_parse_champion(t_vm *vm)
{

	static int					all_champions_found = 0;
	static unsigned int			current_i = 0;

	(void)vm;
	/* next_arg can be set by -n, if not the file descriptor is stored in a temporary array */
	if (1 == all_champions_found)
		ft_exit("Too many champions want to fight");
	++vm->nb_champion;
	if (0 == vm->option.next_arg)
	{
		vm->option.next_arg = &vm->fd_tmp[current_i++];
	}
	if (!(*(int *)".cor" ==
		*(int *)(*vm->option.av + ft_strlen(*vm->option.av) - 4)))
		ft_exit("Extension .cor not found");
	if (IS_NEG((*vm->option.next_arg = open(*vm->option.av, O_RDONLY, 0666))))
		ft_exit("The file can't be read");
	if (vm->nb_champion == MAX_PLAYERS)
		all_champions_found = 1;
	++vm->option.av;
	--vm->option.ac;
	vm->option.next_arg = 0;
	vm->option.state = OPT_STATE_DEFAULT;
}
