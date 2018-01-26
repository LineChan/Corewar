/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_get_int32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/26 00:44:04 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"
#include "ft_printf.h"

int32_t		ft_arena_get_int32(t_vm *vm, int pc)
{
	int8_t	value[4];

	value[0] = ft_arena_get_int8(vm, pc + 0);
	value[1] = ft_arena_get_int8(vm, pc + 1);
	value[2] = ft_arena_get_int8(vm, pc + 2);
	value[3] = ft_arena_get_int8(vm, pc + 3);
	return (ft_endian_convert_int32(*(int32_t *)value));
}
