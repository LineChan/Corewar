/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:09:26 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/20 21:57:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <unistd.h>

#include "ft_printf.h"
void			ft_header_name(t_vm *vm, int const index)
{
	/* Check read's return and align bits if necessary */
	ASSERT(!IS_NEG(read(vm->fd[index], vm->header[index].prog_name,
		ALIGN_4(sizeof(vm->header[index].prog_name)))));
}
