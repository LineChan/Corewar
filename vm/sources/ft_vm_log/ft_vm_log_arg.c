/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:43:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/19 15:26:14 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

// TODO : presentation

void 				ft_vm_log_arg(t_dead_pool *dead_pool)
{
	int		i;
	char	type[3];

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (dead_pool->i_champ->instr.op->arg_types[i] == T_REG)
			type[i] = 'R';
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_IND)
			type[i] = 'I';
		else if (dead_pool->i_champ->instr.op->arg_types[i] == T_DIR)
			type[i] = 'D';
		else
			type[i] = 'X';
		++i;
	}
	ft_log("\t\t[%c] [%c] [%c]\n", type[0], type[1], type[2]);
}
