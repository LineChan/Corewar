/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header_comment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:53:42 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/14 14:33:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "macro.h"
#include <unistd.h>

void				ft_vm_read_header_comment(t_vm *vm, int index)
{
    /* Check read's return and align bits if necessary */
    ASSERT(!IS_NEG(read(vm->fd[index], vm->header[index].comment,
        ALIGN_4(sizeof(vm->header[index].comment)))));
}
