/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:40:21 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

static char	*ft_pf_buffer(t_printf *pf, size_t *size)
{
	static char			buffer[0x100 + 1];
	char				*it;
	uint64_t			nb;

	nb = pf->arg.i;
	it = buffer + 0x100;
	if (0 == nb && 0 == pf->precision)
		*it = 0;
	else
	{
		*--it = '0' + (nb % 10);
		while (0 != (nb /= 10))
			*--it = '0' + (nb % 10);
		pf->precision -= (buffer + 0x100) - it;
		while (0 < pf->precision--)
			*--it = '0';
	}
	*size = (buffer + 0x100) - it;
	return (it);
}

void		ft_pf_handle_u(t_pf_buf *p, t_printf *pf)
{
	char	*buffer;
	size_t	len_buf;

	buffer = ft_pf_buffer(pf, &len_buf);
	ft_pf_pre_padd(p, len_buf, pf);
	ft_pf_buffer_push(p, buffer, len_buf);
	ft_pf_post_padd(p, len_buf, pf);
}

