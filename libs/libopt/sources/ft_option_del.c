/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/20 01:04:51 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_string.h"

static void	ft_option_del_rule(t_list *it)
{
	t_option_rule	*rule;

	rule = C_RULE(it);
	ft_strdel(&rule->name);
	ft_memdel((void **)&rule);
}

static void	ft_option_del_opt(t_list *it)
{
	t_option_list	*node;
	size_t			i;

	node = C_OPTION(it);
	ft_strdel(&node->name);
	i = 0;
	while (i < node->nb_data)
		ft_strdel(&node->data[i++]);
	ft_memdel((void **)node->data);
	ft_memdel((void **)&node);
}

void	ft_option_del(t_option **ptr)
{
	if (0 != *ptr)
	{
		ft_list_apply(&(*ptr)->option_head, &ft_option_del_opt);
		ft_list_apply(&(*ptr)->rule_head, &ft_option_del_rule);
		ft_memdel((void **)ptr);
	}
}
