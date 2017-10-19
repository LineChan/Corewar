/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/20 00:46:12 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_string.h"

static int	ft_option_find_name(t_list *it, void const *name)
{
	return (0 == ft_strcmp((char const *)name, C_OPTION(it)->name));
}

char		**ft_option_find(t_option *opt, char const *name)
{
	t_list	*it;

	it = ft_list_find_data(&opt->option_head, (void *)name, &ft_option_find_name);
	if (0 != it)
		return (C_OPTION(it)->data);
	return (0);
}
