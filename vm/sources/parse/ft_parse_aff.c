/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_aff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 02:25:53 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 00:04:33 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_parse_aff(t_vm *vm, t_parse *parse)
{
	/* Set the next_arg on the options' structure */
	vm->opt.display_aff = 1;
	++parse->av;
	--parse->ac;
	/* An error occurs if there is no argument left */
	if (0 == parse->ac)
		ft_exit("Parsing error near -dump");
	/* Set the next state to get the display value */
	parse->state = OPT_STATE_DEFAULT;
}
