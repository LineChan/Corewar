/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curse_sig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 00:07:29 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 00:17:31 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_curse.h"
#include "ft_string.h"

t_curse_manager			*ft_arena_sig(void)
{
	static t_curse_manager		*p = 0;

	if (0 == p)
		p = (t_curse_manager *)ft_memalloc(sizeof(*p));
	return (p);
}

t_curse_manager			*ft_score_sig(void)
{
	static t_curse_manager		*p = 0;

	if (0 == p)
		p = (t_curse_manager *)ft_memalloc(sizeof(*p));
	return (p);
}
#if 0
t_curse_manager	*ft_curse_sig(void)
{
	static t_curse_manager *p = 0;

	if (0 == p)
		p = (t_curse_manager *)ft_memalloc(sizeof(*p));
	return (p);
}

t_curse_manager	*ft_score_sig(void)
{
	static t_curse_manager *p = 0;

	if (!p)
		p = (t_curse_manager *)ft_memalloc(sizeof(*p));
	return (p);
}

void			ft_curse_del(void)
{
	t_curse_manager	*p;

	p = ft_curse_sig();
	ft_memdel((void **)&p);
}
#endif
