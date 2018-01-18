/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_proc_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:02:22 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 16:42:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

void				ft_del_proc_list(t_vm *vm)
{
	if (ft_list_is_empty(&vm->proc_head))
		return ;
	ft_list_apply(&vm->proc_head, &ft_del_proc);
}
