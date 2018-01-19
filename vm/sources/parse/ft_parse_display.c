/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 02:33:22 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/19 10:22:33 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_parse_display(t_vm *vm, t_parse *parse)
{
	/* Set the next_arg on the options' structure */
	parse->next_arg = &vm->opt.display;
	++parse->av;
	--parse->ac;
	/* An error occurs if there is no argument left */
	if (0 == parse->ac)
		ft_exit("Parsing error near -display");
	/* Set the next state to get the display value */
	parse->state = OPT_STATE_NUMBER;
}
