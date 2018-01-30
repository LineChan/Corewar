/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 00:42:37 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/17 02:09:23 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_parse_nb(t_vm *vm, t_parse *parse)
{
	(void)vm;
	if (0 == parse->next_arg)
		ft_exit("Parsing error");
	/* Options' values can't be negative */
	if (IS_NEG((*parse->next_arg = ft_atoi(*parse->av))))
		ft_exit("Not a positive int");
	++parse->av;
	--parse->ac;
	/* Reset the State Machine to default */
	parse->state = OPT_STATE_DEFAULT;
	parse->next_arg = 0;
}
