/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:40:58 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/07 00:45:01 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"
#include "ft_instruction.h"

void			ft_vm_log_arg(t_instr const *instr)
{
	int		i;
	char	type[3];

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (instr->args[i].type == REG_CODE)
			type[i] = 'R';
		else if (instr->args[i].type == IND_CODE)
			type[i] = 'I';
		else if (instr->args[i].type == DIR_CODE)
			type[i] = 'D';
		else
			type[i] = 'X';
		++i;
	}
	ft_log("\t\t[%c] [%c] [%c]\n", type[0], type[1], type[2]);
}
