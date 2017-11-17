/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:28:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 14:46:00 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO: presentation

int					ft_vm_instr_decode(t_dead_pool *dead_pool)
{
	ft_printf("\t{bblack:ft_vm_instr_champion_decode} {green:in} : %s\n", dead_pool->i_champ->header.prog_name);
	/* Check if the instruction correspond to an instruction */
	if ((*dead_pool->i_champ->pc == 0) || (*dead_pool->i_champ->pc > INSTR_NUMBER))
	{
		if (DEBUG_MODE)
			ft_printf(	"\t{bblack:ft_vm_instr_champion_decode} {red:out}\n");
		return (EXIT_FAILURE);
	}
	/* Copy the information about the instruction in the champion's structure */
	dead_pool->i_champ->instr.op = &g_op_tab[*dead_pool->i_champ->pc];
	/* Read the bytecode if there is one */
	if (dead_pool->i_champ->instr.op->param_byte)
	{
		dead_pool->i_champ->instr.bytecode = (unsigned int)*(dead_pool->i_champ->pc + 1);
		if (DEBUG_MODE)
			ft_printf("\t{bblack:ft_vm_instr_champion_decode} {green:out} : %s\n", dead_pool->i_champ->header.prog_name);
		/* Set up the jump to make in the memory according to the parameters */
		return (ft_vm_instr_jump(dead_pool));
	}
	if (DEBUG_MODE)
		ft_printf("\t{bblack:ft_vm_instr_champion_decode} {green:out}\n");
	return (EXIT_SUCCESS);
}
