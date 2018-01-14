/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find_tail.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 10:47:07 by igomez            #+#    #+#             */
/*   Updated: 2017/03/04 20:41:11 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find_tail(t_list *head, int (*func)(t_list *))
{
	t_list	*it;

	it = head->prev;
	while (it != head)
	{
		if (func(it))
			return (it);
		it = it->prev;
	}
	return (0);
}
