/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 02:14:33 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/20 16:10:50 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_parse_n(t_vm *vm, t_parse *parse)
{
	int		n;

	++parse->av;
	--parse->ac;
	/* An error occurs if there is no argument left */
	if (parse->ac < 2)
		ft_exit("Parsing error near -n");
	/* Check if the process' number is valid */
	n = ft_atoi(*parse->av);
	if ((n < 1) || (n > MAX_PLAYERS) || vm->fd[n - 1])
		ft_exit("Wrong champion's number");
	++parse->av;
	--parse->ac;
	/* Set the next_arg on the options' structure */
	parse->next_arg = &vm->fd[n - 1];
	/* Set the next state to get the process' file */
	parse->state = OPT_STATE_PROC;
}
