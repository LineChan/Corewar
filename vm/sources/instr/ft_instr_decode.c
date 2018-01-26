/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_decode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:05:09 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/25 23:22:24 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_instruction.h"

uint8_t			ft_instr_decode(t_vm *vm, t_proc *proc)
{
	return (ft_instr_parse(vm, proc, ft_instr_setup(vm,proc)));
}
