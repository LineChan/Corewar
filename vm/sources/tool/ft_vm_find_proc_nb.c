/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_find_proc_nb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 22:39:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/26 00:48:14 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

t_list			*ft_vm_find_proc_nb(t_list *head, int nb)
{
    t_list  *it;

    it = head->next;
    while (it != head)
    {
        if (C_PROCESS(it)->process_nb == nb)
            return (it);
		it = it->next;
    }
    return (0);
}
