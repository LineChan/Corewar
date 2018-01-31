/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_stealth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:39:41 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/30 15:43:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void		ft_parse_stealth(t_vm *vm, t_parse *parse)
{
	++parse->av;
	--parse->ac;
	vm->opt.stealth = 1;
	/* Reset the State Machine to default */
	parse->state = OPT_STATE_DEFAULT;
}
