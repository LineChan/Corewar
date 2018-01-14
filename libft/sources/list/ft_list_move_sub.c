/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_move_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 13:02:47 by igomez            #+#    #+#             */
/*   Updated: 2017/03/18 10:12:56 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_move_sub(t_list *first_src, t_list *last_src, t_list *head_dst)
{
	t_list		*after;

	after = head_dst->next;
	first_src->prev->next = last_src->next;
	last_src->next->prev = first_src->prev;
	head_dst->next = first_src;
	first_src->prev = head_dst;
	last_src->next = after;
	after->prev = last_src;
}
