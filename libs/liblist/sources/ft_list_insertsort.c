/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insertsort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/04/17 15:23:10 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_insertsort(t_list *list_head, int (*f)(t_list *a, t_list *b))
{
	t_list	*right;
	t_list	*left;

	if (ft_list_is_singular(list_head))
		return ;
	right = list_head->next->next;
	while (right != list_head)
	{
		left = right->prev;
		if (f(left, right) > 0)
		{
			left = left->prev;
			while (left != list_head && f(left, right) > 0)
				left = left->prev;
			ft_list_del(right);
			ft_list_add(right, left);
		}
		right = right->next;
	}
}
