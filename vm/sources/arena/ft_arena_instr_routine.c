/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_instr_routine.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:58:32 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 14:48:18 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_arena_instr_routine(t_vm *vm, t_proc *proc)
{
	uint8_t			ret;

	/* Decode the instruction */
	ret = ft_instr_decode(vm, proc);
	
}
