/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_selectsort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/04/17 15:23:18 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_selectsort(t_list *list_head, int (*f)(t_list *a, t_list *b))
{
	t_list	*it;
	t_list	*check;
	t_list	*ref;

	if (ft_list_is_singular(list_head))
		return ;
	it = list_head->next;
	while (it != list_head->prev)
	{
		ref = it;
		check = it->next;
		while (check != list_head)
		{
			if (f(check, ref) < 0)
				ref = check;
			check = check->next;
		}
		if (it != ref)
		{
			ft_list_swap(it, ref);
			it = ref;
		}
		it = it->next;
	}
}
