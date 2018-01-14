/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_apply_tail.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/29 00:34:12 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_apply_tail(t_list *head, void (*func)(t_list *))
{
	t_list	*it;
	t_list	*prev;

	if (0 != head)
	{
		it = head->prev;
		while (it != head)
		{
			prev = it->prev;
			func(it);
			it = prev;
		}
	}
}
