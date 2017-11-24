/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 10:47:07 by igomez            #+#    #+#             */
/*   Updated: 2017/10/02 01:24:00 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find_data(t_list *head, void const *data,
							int (*func)(t_list *, void const *))
{
	t_list	*it;

	it = head->next;
	while (it != head)
	{
		if (func(it, data))
			return (it);
		it = it->next;
	}
	return (0);
}
