/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:39:12 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

static char	*ft_pf_buffer(t_printf *pf, size_t *size)
{
	static char	buffer[0x100 + 1];
	char		*it;

	it = buffer + 0x100;
	if (0 == pf->arg.i && 0 == pf->precision)
		*it = 0;
	else
	{
		*--it = '0' + (pf->arg.i % 10);
		while (0 != (pf->arg.i /= 10))
			*--it = '0' + (pf->arg.i % 10);
		pf->precision -= (buffer + 0x100) - it;
		while (0 < pf->precision--)
			*--it = '0';
	}
	*size = (buffer + 0x100) - it;
	return (it);
}

void		ft_pf_handle_d(t_pf_buf *p, t_printf *pf)
{
	char	*buffer;
	size_t	len_buf;
	int		prefix;

	if (0 > (intmax_t)pf->arg.i)
	{
		prefix = '-';
		pf->arg.i = -(intmax_t)pf->arg.i;
	}
	else if (pf->flags & PF_FLAG_PLUS)
		prefix = '+';
	else if (pf->flags & PF_FLAG_SPACE)
		prefix = ' ';
	else if (pf->flags & PF_FLAG_SIGNED)
		prefix = '-';
	else
		prefix = 0;
	buffer = ft_pf_buffer(pf, &len_buf);
	pf->width -= (0 != prefix);
	if (pf->flags & PF_FLAG_ZERO)
	{
		if (0 != prefix)
			ft_pf_buffer_add(p, prefix);
		ft_pf_pre_padd(p, len_buf, pf);
	}
	else
	{
		ft_pf_pre_padd(p, len_buf, pf);
		if (0 != prefix)
			ft_pf_buffer_add(p, prefix);
	}
	ft_pf_buffer_push(p, buffer, len_buf);
	ft_pf_post_padd(p, len_buf, pf);
}

