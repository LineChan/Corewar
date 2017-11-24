/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 10:47:07 by igomez            #+#    #+#             */
/*   Updated: 2017/03/04 20:41:07 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *head, int (*func)(t_list *))
{
	t_list	*it;

	it = head->next;
	while (it != head)
	{
		if (func(it))
			return (it);
		it = it->next;
	}
	return (0);
}
