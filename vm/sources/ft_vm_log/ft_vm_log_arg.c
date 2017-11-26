/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_log_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:40:58 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 15:45:40 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_log.h"

void			ft_vm_log_arg(t_process *proc)
{
	int		i;
	char	type[3];

	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		if (proc->op->arg_types[i] == T_REG)
			type[i] = 'R';
		else if (proc->op->arg_types[i] == T_IND)
			type[i] = 'I';
		else if (proc->op->arg_types[i] == T_DIR)
			type[i] = 'D';
		else
			type[i] = 'X';
		++i;
	}
	ft_log("\t\t[%c] [%c] [%c]\n", type[0], type[1], type[2]);
}
