/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:39:53 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

void	ft_pf_handle_n(t_pf_buf *p, t_printf *pf)
{
	if (PF_l == pf->length)
		*(long long *)pf->arg.p = p->nb;
	else if (PF_ll == pf->length)
		*(long long *)pf->arg.p = p->nb;
	else if (PF_h == pf->length)
		*(uint16_t *)pf->arg.p = p->nb;
	else if (PF_hh == pf->length)
		*(uint8_t *)pf->arg.p = p->nb;
	else if (PF_z == pf->length)
		*(size_t *)pf->arg.p = p->nb;
	else if (PF_t == pf->length)
		*(ptrdiff_t *)pf->arg.p = p->nb;
	else if (PF_j == pf->length)
		*(uintmax_t *)pf->arg.p = p->nb;
	else
		*(int32_t *)pf->arg.p = p->nb;
}
