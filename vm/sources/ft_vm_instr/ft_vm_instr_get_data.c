/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_get_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:18:58 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/08 18:17:09 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"

int			ft_vm_instr_get_data(size_t size, uint8_t *pc, t_vm *vm)
{
	uint32_t	tmp;
	size_t		i;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		if (&pc[size - i - 1] == &vm->arena[0][MEM_SIZE])
			pc = vm->arena[0];
		tmp = (tmp << 8) | pc[size - ++i];
	}
	if (1 == size)
		return (*(int8_t *)&tmp);
	if (2 == size)
	{
		if (IS_BIG_ENDIAN)
			return (*(int16_t *)&tmp);
		return (ft_endian_convert_int16(*(int16_t *)&tmp));
	}
	if (IS_BIG_ENDIAN)
		return (*(int32_t *)&tmp);
	return (ft_endian_convert_int32(*(int32_t *)&tmp));
}
