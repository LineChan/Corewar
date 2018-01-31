/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_round_limit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:34:31 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 17:16:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_parse_round_limit(t_vm *vm, t_parse *parse)
{
	/* Set the next_arg on the options' structure */
	parse->next_arg = &vm->opt.round_limit;
	++parse->av;
	--parse->ac;
	/* An error occurs if there is no argument left */
	if (0 == parse->ac)
		ft_exit("Parsing error next round limit");
	parse->state = OPT_STATE_NUMBER;
}
