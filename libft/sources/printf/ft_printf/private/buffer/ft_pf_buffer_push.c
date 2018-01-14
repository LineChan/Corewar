/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_buffer_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:37:30 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

static void	*ft_pf_copy(char *dst, char const *src, size_t size)
{
	char	*p1;
	char	*p2;

	if (dst != src)
	{
		p1 = dst;
		p2 = (char *)src;
		while (size >= sizeof(uintmax_t))
		{
			*(uintmax_t *)p1 = *(uintmax_t *)p2;
			p1 += sizeof(uintmax_t);
			p2 += sizeof(uintmax_t);
			size -= sizeof(uintmax_t);
		}
		while (0 < size)
		{
			*p1++ = *p2++;
			--size;
		}
	}
	return (dst);
}

static void	ft_pf_buffer(t_pf_buf *p, char const *data, size_t size)
{
	extern int	errno;

	if (0 < p->limit)
	{
		if (p->limit >= size)
		{
			if (0 != p->buffer)
				ft_pf_copy(p->buffer + p->nb, data, size);
			p->limit -= size;
		}
		else
		{
			if (0 != p->buffer)
				ft_pf_copy(p->buffer + p->nb, data, p->limit);
			p->limit = 0;
		}
	}
	else
		errno = ENOMEM;
}

static void	ft_pf_buffer_alloc(t_pf_buf *p, char const *data, size_t size)
{
	size_t	capacity;

	/* Next power of two of p->nb+size */
	capacity = (p->nb + size) - 1;
	capacity |= capacity >> 1;
	capacity |= capacity >> 2;
	capacity |= capacity >> 4;
	capacity |= capacity >> 8;
	capacity |= capacity >> 16;
	++capacity;
	if (p->alloc_capacity != capacity)
	{
		p->alloc_capacity = capacity;
		p->buffer = (char *)realloc(p->buffer, p->alloc_capacity * sizeof(char));
	}
	ft_pf_copy(p->buffer + p->nb, data, size);
}

void		ft_pf_buffer_push(t_pf_buf *p, char const *data, size_t size)
{

	if (p->buffer_malloc == PF_ALLOC_ON)
		ft_pf_buffer_alloc(p, data, size);
	else
		ft_pf_buffer(p, data, size);
	p->nb += size;
}

