/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_get_int16.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/26 00:43:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"
#include "ft_printf.h"

int16_t	ft_arena_get_int16(t_vm *vm, int pc)
{
	int8_t	value[2];

	value[0] = ft_arena_get_int8(vm, pc + 0);
	value[1] = ft_arena_get_int8(vm, pc + 1);
	return (ft_endian_convert_int16(*(int16_t *)value));
}
