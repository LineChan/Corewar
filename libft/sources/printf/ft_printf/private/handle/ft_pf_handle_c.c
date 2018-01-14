/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:38:55 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"
#include <stdlib.h>

void	ft_pf_handle_c(t_pf_buf *p, t_printf *pf)
{
   char  buf[0x10];
	size_t	len;

	if (PF_l == pf->length || 0 == (pf->specifier & 32))
	{
		len = ft_pf_wctomb(buf, pf->arg.i);
		ft_pf_pre_padd(p, len, pf);
		ft_pf_buffer_push(p, buf, len);
		ft_pf_post_padd(p, len, pf);
	}
	else
	{
		ft_pf_pre_padd(p, 1, pf);
		ft_pf_buffer_add(p, pf->arg.i);
		ft_pf_post_padd(p, 1, pf);
	}
}
