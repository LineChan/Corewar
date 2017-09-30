/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_add_rule.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/28 17:54:46 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include <stdlib.h>

#include <stdio.h>
void	ft_option_add_rule(t_option *opt, char const *rule, t_option_key key)
{
	char	*p;

	++opt->rule_count;
	opt->rule_list = realloc(opt->rule_list, opt->rule_count);
	opt->rule_list[opt->rule_count - 1].key = key;
	p = opt->rule_list[opt->rule_count - 1].name;
	while (0 != *rule)
		*p++ = *rule++;
	*p = 0;
}
