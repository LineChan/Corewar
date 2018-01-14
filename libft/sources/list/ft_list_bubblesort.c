/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bubblesort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/04/17 15:23:06 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_bubblesort(t_list *list_head, int (*f)(t_list *a, t_list *b))
{
	t_list	*it;
	int		swaped;

	if (ft_list_is_singular(list_head))
		return ;
	swaped = 1;
	while (swaped)
	{
		swaped = 0;
		it = list_head->next->next;
		while (it != list_head)
		{
			if (f(it->prev, it) > 0)
			{
				ft_list_swap(it->prev, it);
				swaped = 1;
			}
			it = it->next;
		}
	}
}
