/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_display_live.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:56:14 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/03 16:47:07 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_vm_display_live(t_vm *vm, t_list *it)
{
	if (!it)
		return ;
	ft_printf("Player %d (%s) is said to be alive\n",
				C_PROCESS(it)->parent_nb,
				vm->header[C_PROCESS(it)->parent_nb - 1].prog_name);
}
