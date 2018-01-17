/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:12:31 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/17 15:54:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <unistd.h>

void			ft_header_comment(t_vm *vm, int const index)
{
	/* Check read's return and align bits if necessary */
	ASSERT(!IS_NEG(read(vm->fd[index], vm->header[index].comment,
		ALIGN_4(sizeof(vm->header[index].comment)))));
}
