/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_find_proc_nb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 22:39:30 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 16:29:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

static int             ft_vm_find_proc_nb_helper(t_list *it, void const *context)
{
   return (C_PROCESS(it)->process_nb == *(int *)context);
}

t_list                 *ft_vm_find_proc_nb(t_list *head, int nb)
{
       return (ft_list_find_data(head, (void const *)&nb,
				   &ft_vm_find_proc_nb_helper));
}
