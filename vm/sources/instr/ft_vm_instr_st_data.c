/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_instr_st_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:09:05 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/05 16:03:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void			ft_vm_instr_st_data(void *dst,
									void const *src,
									int size)
{
	while (size--)
	{
		*(char *)dst++ = *(char*)src++;
	}
}
