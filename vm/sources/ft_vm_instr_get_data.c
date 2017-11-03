/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_get_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:49:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/03 15:43:56 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

//TODO : presentation
// by illan91

int				ft_vm_instr_get_data(size_t size, uint8_t *pc)
{
	if (1 == size)
		return (*pc);
	if (2 == size)
	{
		if (IS_BIG_ENDIAN)
			return (*(int16_t *)pc);
		return (ft_endian_convert_int16(*(int16_t *)pc));
	}
	if (IS_BIG_ENDIAN)
		return (*(int32_t *)pc);
	return (ft_endian_convert_int32(*(int32_t *)pc));
}
