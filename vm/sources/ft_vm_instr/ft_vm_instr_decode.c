/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:28:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/09 20:32:09 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO: presentation

int					ft_vm_instr_decode(t_champion *champ)
{
	ft_printf("DECODE IN\n");
	if (!((*champ->pc > 0) && (*champ->pc <= INSTR_NUMBER)))
		return (EXIT_FAILURE);
	champ->instr.op = &g_op_tab[*champ->pc];
	if (champ->instr.op->param_byte)
	{
		champ->instr.bytecode = (unsigned int)*(champ->pc + 1);
		ft_vm_instr_jump(champ);
	}
	if (DEBUG_MODE)
	{
		ft_printf("champion->op.name : '%s'\n", champ->instr.op->name);
		ft_printf("champion->live : %d\n", champ->live);
	}
	ft_printf("DECODE OUT\n");
	return (EXIT_SUCCESS);
}
