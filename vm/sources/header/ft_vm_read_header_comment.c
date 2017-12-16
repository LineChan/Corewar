/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_header_comment.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:53:42 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/10 23:41:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "macro.h"
#include "ft_printf.h"
#include <unistd.h>

void				ft_vm_read_header_comment(t_vm *vm, int index)
{
    ASSERT(!IS_NEG(read(vm->fd[index], vm->header[index].comment,
        ALIGN_4(sizeof(vm->header[index].comment)))));
}
