/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:32:10 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/19 19:15:34 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/*
** Virtual Machine singleton
*/

void        ft_vm_allocation(t_vm *vm)
{
    if (!(vm->arena = ft_memalloc(sizeof(char) * MEM_SIZE)))
        EXIT_FAIL("FAILED ALLOCATION");
    ft_printf("vm allocation OK!\n");
}

void        ft_vm_del(t_vm  *vm)
{
    ft_memdel((void **)vm);
}
