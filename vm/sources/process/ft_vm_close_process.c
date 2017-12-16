/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_close_process.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:47:37 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 01:08:51 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_string.h"

void			ft_vm_close_process(t_list *node)
{
	t_process	*ptr;

	ptr = C_PROCESS(node);
	if (!ptr)
		return ;
	ft_list_del(node);
	ft_memdel((void **)&ptr);
}
