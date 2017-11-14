/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_decode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:28:52 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 16:25:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
//TODO: presentation

int					ft_vm_instr_decode(t_dead_pool *dead_pool)
{
	if (DEBUG_MODE)
		ft_printf("\n\t{bblack:ft_vm_instr_champion_decode} {green:in}\n");

	if (IS_NEG(*dead_pool->champ[dead_pool->idx]->pc)
			|| (*dead_pool->champ[dead_pool->idx]->pc > INSTR_NUMBER))
		{
			if (DEBUG_MODE)
				ft_printf(	"\t{bblack:ft_vm_instr_champion_decode} {green:out}\n");
			return (EXIT_FAILURE);
		}
	dead_pool->champ[dead_pool->idx]->instr.op = &g_op_tab[*dead_pool->champ[dead_pool->idx]->pc];
	if (dead_pool->champ[dead_pool->idx]->instr.op->param_byte)
	{
		dead_pool->champ[dead_pool->idx]->instr.bytecode = (unsigned int)*(dead_pool->champ[dead_pool->idx]->pc + 1);
		if (DEBUG_MODE)
			ft_printf("\t{bblack:ft_vm_instr_champion_decode} {green:out}\n");
		return (ft_vm_instr_jump(dead_pool));
	}
	return (EXIT_SUCCESS);





	#if 0
	if (IS_NEG(*dead_pool->i_champ->pc) || (*dead_pool->i_champ->pc > INSTR_NUMBER))
	{
		if (DEBUG_MODE)
			ft_printf(	"\t{bblack:ft_vm_instr_champion_decode} {green:out}\n");
		return (EXIT_FAILURE);
	}




	dead_pool->i_champ->instr.op = &g_op_tab[*dead_pool->i_champ->pc];
	if (dead_pool->i_champ->instr.op->param_byte)
	{
		dead_pool->i_champ->instr.bytecode = (unsigned int)*(dead_pool->i_champ->pc + 1);
		if (DEBUG_MODE)
			ft_printf("\t{bblack:ft_vm_instr_champion_decode} {green:out}\n");
		return (ft_vm_instr_jump(dead_pool));
	}
	if (DEBUG_MODE)
		ft_printf("\t{bblack:ft_vm_instr_champion_decode} {green:out}\n");
	return (EXIT_SUCCESS);
	#endif
}
