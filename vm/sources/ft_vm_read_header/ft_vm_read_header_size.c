/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:48:11 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/10 23:42:45 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "macro.h"
#include "endian.h"
#include "ft_printf.h"
#include <unistd.h>

void 			ft_vm_read_header_size(t_vm *vm, int index)
{
	ASSERT(!IS_NEG(read(vm->fd[index], &vm->header[index].prog_size,
		sizeof(vm->header[index].prog_size))));
	if (IS_LITTLE_ENDIAN)
		vm->header[index].prog_size =
		ft_endian_convert_uint32(vm->header[index].prog_size);
	ASSERT(vm->header[index].prog_size <= CHAMP_MAX_SIZE);
}
