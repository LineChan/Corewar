/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 13:04:29 by igomez            #+#    #+#             */
/*   Updated: 2017/04/05 21:29:48 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_list_len(t_list *head)
{
	size_t 	count;
	t_list	*it;

	count = 0;
	it = head->next;
	while (it != head)
	{
		++count;
		it = it->next;
	}
	return (count);
}
