/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:44:01 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

static char	*ft_pf_buffer(t_printf *pf, size_t *size)
{
	static char	buffer[0x100 + 1];
	char		*it;
	uint64_t	nb;

	nb = pf->arg.i;
	it = buffer + 0x100;
	if (0 == nb && 0 == pf->precision)
		*it = 0;
	else
	{
		*--it = '0' + (nb & 1);
		while (0 != (nb >>= 1))
			*--it = '0' + (nb & 1);
		pf->precision -= (buffer + 0x100) - it;
		while (0 < pf->precision--)
			*--it = '0';
	}
	*size = (buffer + 0x100) - it;
	return (it);
}

static char	*ft_pf_prefix(t_printf *pf, size_t *size, int const lower)
{
	static char		prefix[0x10];
	char			*it;

	it = prefix;
	if (pf->flags & PF_FLAG_POUND)
	{
		*it++ = '0';
		*it++ = 'B' | lower;
	}
	*it = 0;
	*size = it - prefix;
	return (prefix);
}

void		ft_pf_handle_b(t_pf_buf *p, t_printf *pf)
{
	char	*buffer;
	char	*prefix;
	size_t	len_buf;
	size_t	len_pfx;

	if (0 == pf->arg.i)
		pf->flags &= ~PF_FLAG_POUND;
	buffer = ft_pf_buffer(pf, &len_buf);
	prefix = ft_pf_prefix(pf, &len_pfx, pf->specifier & 32);
	pf->width -= len_pfx;
	if (pf->flags & PF_FLAG_ZERO)
	{
		ft_pf_buffer_push(p, prefix, len_pfx);
		ft_pf_pre_padd(p, len_buf, pf);
	}
	else
	{
		ft_pf_pre_padd(p, len_buf, pf);
		ft_pf_buffer_push(p, prefix, len_pfx);
	}
	ft_pf_buffer_push(p, buffer, len_buf);
	ft_pf_post_padd(p, len_buf, pf);
}

