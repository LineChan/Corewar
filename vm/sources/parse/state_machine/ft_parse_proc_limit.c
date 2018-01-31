/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_proc_limit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:43:24 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 17:47:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_parse_proc_limit(t_vm *vm, t_parse *parse)
{
	/* Set the next_arg on the options' structure */
	parse->next_arg = &vm->opt.proc_limit;
	++parse->av;
	--parse->ac;
	/* An error occurs if there is no argument left */
	if (0 == parse->ac)
		ft_exit("Parsing error near -proc-limit");
	/* Set the next state to get the proc-limit value */
	parse->state = OPT_STATE_NUMBER;
}
