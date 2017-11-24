/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_add_rule.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/20 01:04:45 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_string.h"
#include <stdlib.h>

void	ft_option_add_rule(t_option *opt, char const *rule, t_option_key key)
{
	t_option_rule	*optrule;

	optrule = (t_option_rule *)ft_calloc(1, sizeof(t_option_rule));
	optrule->name = ft_strdup(rule);
	optrule->key = key;
	ft_list_add_tail(&optrule->list, &opt->rule_head);
}
