/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_sti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:56:46 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/14 23:34:16 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

// TODO: presentation
/*
* brief      		Execute sti : Take a registry and 2 indexes
* (potentially registries), add the two indexes and use this result
* as an address where the value of the first parameter will be copied.
*
* param arena
* param champ
*/

extern uint8_t	g_direct_jump_table_from_instr[17];

// TODO : remove libc.h
#include <libc.h>
void 			ft_vm_instr_sti(unsigned char arena[], t_dead_pool *dead_pool)
{
	int				i;
	int				reg;
	int				copy_at_address;
	unsigned char   *ptr;

	DEBUG_MODE ? ft_printf("{yellow:sti}\n") : 0;
    i = 1;
    copy_at_address = 0;
	/* Set a pointer at the beginning of the arguments */
    ptr = dead_pool->champ[CHAMP_IDX].pc + 2;
    reg = *ptr;
	if (!IS_REG(reg))
	{
		dead_pool->champ[CHAMP_IDX].pc += 1;
		return ;
	}
    DEBUG_MODE ? ft_printf("reg : %hhx\n", reg) : 0;
    ptr += dead_pool->champ[CHAMP_IDX].instr.arg_jump[0];
	/* Read arguments */
    while (i < dead_pool->champ[CHAMP_IDX].instr.op->nb_args)
    {
        if (dead_pool->champ[CHAMP_IDX].instr.op->arg_types[i] == T_REG)
		{
			if (!IS_REG(*ptr))
			{
				dead_pool->champ[CHAMP_IDX].pc += 1;
				return ;
			}
            copy_at_address += dead_pool->champ[CHAMP_IDX].reg[*ptr];
		}
        else if (dead_pool->champ[CHAMP_IDX].instr.op->arg_types[i] == T_IND)
            copy_at_address += dead_pool->champ[CHAMP_IDX].pc - arena + (ft_instruction_get_data(2, ptr) % IDX_MOD);
        else
            copy_at_address += ft_instruction_get_data(g_direct_jump_table_from_instr[dead_pool->champ[CHAMP_IDX].instr.op->numero], ptr);
        ptr += dead_pool->champ[CHAMP_IDX].instr.arg_jump[i];
        ++i;
    }
    DEBUG_MODE ? ft_printf("final copy_at_address : %d\n", copy_at_address) : 0;
    /* Store the value from the register */
    arena[MOD(copy_at_address)] = dead_pool->champ[CHAMP_IDX].reg[reg];
    /* Move the Program Counter */
    dead_pool->champ[CHAMP_IDX].pc += 2 + dead_pool->champ[CHAMP_IDX].instr.arg_jump[0] + dead_pool->champ[CHAMP_IDX].instr.arg_jump[1] + dead_pool->champ[CHAMP_IDX].instr.arg_jump[2];
}
