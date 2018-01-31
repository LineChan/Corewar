/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 02:25:53 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 15:46:19 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_parse_dump(t_vm *vm, t_parse *parse)
{
	/* Set the next_arg on the options' structure */
	parse->next_arg = &vm->opt.dump;
	++parse->av;
	--parse->ac;
	/* An error occurs if there is no argument left */
	if (0 == parse->ac)
		ft_exit("Parsing error near -dump");
	/* Set the next state to get the dump value */
	parse->state = OPT_STATE_NUMBER;
}
