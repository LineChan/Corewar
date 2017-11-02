/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_bytecode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:07:45 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/02 14:19:52 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: presentation
# include "ft_vm.h"

void			ft_vm_instr_bytecode(t_champion *champ)
{
	champ->pc += 1;
	champ->instr.bytecode = (unsigned int)*(champ->pc);
	champ->pc += 1;
	DEBUG_MODE ? ft_printf("instr->bytecode '%b'\n", champ->instr.bytecode) : 0;
}
