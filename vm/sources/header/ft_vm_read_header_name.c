/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:44:00 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:35:39 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "macro.h"
#include <unistd.h>

void 			ft_vm_read_header_name(t_vm *vm, int index)
{
    /* Check read's return and align bits if necessary */
	ASSERT(!IS_NEG(read(vm->fd[index], &vm->header[index].prog_name,
		ALIGN_4(sizeof(vm->header[index].prog_name)))));
}
