/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_bytecode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:07:45 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/28 02:24:26 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: presentation
# include "ft_vm.h"

void			ft_vm_instr_bytecode(t_champion *champ)
{
	champ->instr.bytecode = (unsigned int)*(champ->pc + 1);
	champ->pc += 1;
	ft_printf("instr->bytecode '%b'\n", champ->instr.bytecode);
}
