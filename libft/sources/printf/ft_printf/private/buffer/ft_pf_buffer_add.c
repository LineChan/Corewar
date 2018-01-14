/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_buffer_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:37:24 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"
#include <stdlib.h>
#include <errno.h>

static void	ft_pf_buffer(t_pf_buf *p, int c)
{
	extern int	errno;

	if (0 < p->limit)
	{
		if (0 != p->buffer)
			p->buffer[p->nb] = c;
		--p->limit;
	}
	else
		errno = ENOMEM;
}

static void	ft_pf_buffer_alloc(t_pf_buf *p, int c)
{
	if (p->alloc_capacity <= p->nb)
	{
		p->alloc_capacity <<= 1;
		p->buffer = (char *)realloc(p->buffer, p->alloc_capacity * sizeof(char));
	}
	p->buffer[p->nb] = c;
}

void	ft_pf_buffer_add(t_pf_buf *p, int c)
{
	if (p->buffer_malloc == PF_ALLOC_ON)
		ft_pf_buffer_alloc(p, c);
	else
		ft_pf_buffer(p, c);
	++p->nb;
}

