/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/29 12:58:42 by igomez            #+#    #+#             */
/*   Updated: 2017/03/05 19:14:12 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_swap(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = a->prev;
	ft_list_del(a);
	ft_list_add(a, b);
	ft_list_del(b);
	ft_list_add(b, tmp);
}
