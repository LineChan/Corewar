/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_start_cycle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:54:00 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 15:28:51 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_parse_start_cycle(t_vm *vm, t_parse *parse)
{
	/* Set the next_arg on the options' structure */
	parse->next_arg = &vm->current_cycle;
	++parse->av;
	--parse->ac;
	/* An error occurs if there is no argument left */
	if (0 == parse->ac)
		ft_exit("Parsing error next start_cycle");
	parse->state = OPT_STATE_NUMBER;
}
