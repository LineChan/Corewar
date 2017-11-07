/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_ldi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:32:54 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/07 17:49:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO : presentation
// TODO : carry
// TODO : libc.h

#if 0
#endif
exter uint8_t g_direct_jump_table_from_instr[17];

void				ft_vm_instr_ldi(unsigned char arena[],
									t_dead_pool *dead_pool,
									t_champion *champ)
{
	unsigned int		i;
	unsigned int		value_to_load;
	unsigned char		*ptr;

	(void)dead_pool;
	ptr = champ->pc + 2;
	i = 0;
	while (i < (champ->instr.op->nb_args - 1))
	{
		if (champ->instr.arg_types[i] == T_REG)
			value_to_load += champ->reg[*ptr]
		else if (champ->instr.arg_types[i] == T_IND)
			value_to_load += arena[MOD((champ->pc - arena) + (ft_instruction_get_data(2, ptr) % IDX_MOD))];
		else if (champ->intr.arg_type[i] == T_DIR)
			value_to_load += arena[MOD(ft_instruction_get_data(g_direct_jump_table_from_instr(champ->instr.op->numero), ptr))];
		++i;
		ptr += champ->instr.arg_jump[i];
	}
	// TODO : finish LDI
}
