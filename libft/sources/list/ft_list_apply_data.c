/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_apply_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/18 20:34:37 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_apply_data(t_list *head, void *data, void (*func)(t_list *, void *))
{
	t_list	*it;
	t_list	*next;

	if (0 != head)
	{
		it = head->next;
		while (it != head)
		{
			next = it->next;
			func(it, data);
			it = next;
		}
	}
}
