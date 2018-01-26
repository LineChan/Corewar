/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_set_int32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/26 00:45:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"
#include "ft_printf.h"

void	ft_arena_set_int32(t_vm *vm, int pc, int data)
{
	uint8_t		value[4];

	*(uint32_t *)value = ft_endian_convert_int32(data);
	ft_arena_set_int8(vm, pc + 0, value[0]);
	ft_arena_set_int8(vm, pc + 1, value[1]);
	ft_arena_set_int8(vm, pc + 2, value[2]);
	ft_arena_set_int8(vm, pc + 3, value[3]);
}
