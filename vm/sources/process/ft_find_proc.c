/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:56:18 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/18 18:07:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

static int		ft_find_proc_nb(t_list *it, void const *context)
{
	return (C_PROCESS(it)->proc_nb == *(int *)context);
}

t_list			*ft_find_proc(t_list *head, int nb)
{
	return (ft_list_find_data(head, (void const *)&nb, &ft_find_proc_nb));
}
