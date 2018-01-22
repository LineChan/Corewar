/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:56:00 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/21 13:19:21 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "endian.h"
#include <unistd.h>

void			ft_header_size(t_vm *vm, int const index)
{
	/* Check read's return and align bits if necessary */
	ASSERT(!IS_NEG(read(vm->fd[index], &vm->header[index].prog_size,
			sizeof(vm->header[index].prog_size))));
	/* Convert the process' size to big endian */
	if (IS_LITTLE_ENDIAN)
	{
		vm->header[index].prog_size =
			ft_endian_convert_uint32(vm->header[index].prog_size);
	}
	/* Check if the process' magic number is valid */
	ASSERT(vm->header[index].prog_size <= CHAMP_MAX_SIZE);
}
