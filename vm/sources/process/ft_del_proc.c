/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:14:07 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 14:48:15 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

void			ft_del_proc(t_list *node)
{
	t_proc		*ptr;

	ptr = C_PROCESS(node);
	if (!ptr)
		return ;
	if (ptr->instr)
		ft_memdel((void **)&ptr->instr);
	ft_list_del(node);
	ft_memdel((void **)&ptr);
}
