/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/28 19:11:49 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"

int		ft_option_compare(char const *s1, char const *s2)
{
	uint8_t	*p;
	uint8_t	*q;

	p = (uint8_t *)s1;
	q = (uint8_t *)s2;
	while (0 != *p && *p == *q)
	{
		++p;
		++q;
	}
	return (*p - *q);
}

void	ft_option_copy(char const *from, char *to)
{
	char	*p;

	p = to;
	while (0 != (*p++ = *from++))
		continue ;
}

size_t	ft_option_size(char const *name)
{
	char const	*p;

	p = name;
	while (0 != *p)
		++p;
	return (p - name);
}
