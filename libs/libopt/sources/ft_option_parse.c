/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/24 20:58:50 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include <stdlib.h>

static void	ft_option_insert(t_option *opt, char const *name, char const *data)
{
	int		i;

	i = opt->option_count++ - 1;
	opt->option_list = realloc(opt->option_list, opt->option_count);
	while (i >= 0 && 0 < ft_option_compare(opt->option_list[i].name, name))
	{
		ft_option_copy(opt->option_list[i].name, opt->option_list[i + 1].name);
		ft_option_copy(opt->option_list[i].data, opt->option_list[i + 1].data);
		--i;
	}
	ft_option_copy(name, opt->option_list[i + 1].name);
	ft_option_copy(data, opt->option_list[i + 1].data);
}

static int	ft_option_rule(t_option *opt, int ac, size_t rule, char const *sub)
{
	if (opt->rule_list[rule].key == OPTION_KEY_BOOL)
	{
		ft_option_insert(opt, opt->argv[ac], "true");
		return (1);
	}
	if (0 != sub)
	{
		ft_option_insert(opt, opt->argv[ac], sub);
		return (1);
	}
	if (opt->argc == ac + 1)
		return (0);
	ft_option_insert(opt, opt->argv[ac], opt->argv[ac + 1]);
	return (2);
}

static int	ft_option_parse_rule(t_option *opt, int ac)
{
	size_t	i;
	size_t	len;
	char	*sub;

	i = 0;
	sub = 0;
	while (i < opt->rule_count)
	{
		len = ft_option_size(opt->rule_list[i].name);
		if (ft_option_size(opt->argv[ac]) > len && '=' == opt->argv[ac][len])
		{
			opt->argv[ac][len] = 0;
			sub = opt->argv[ac] + len + 1;
		}
		if (0 == ft_option_compare(opt->argv[ac], opt->rule_list[i].name))
			return (ft_option_rule(opt, ac, i, sub));
		sub = 0;
		++i;
	}
	return (0);
}

void		ft_option_parse(t_option *opt)
{
	int		ac;
	int		rule_jmp;

	ac = 1;
	while (ac < opt->argc)
	{
		if ('-' != opt->argv[ac][0])
			break ;
		rule_jmp = ft_option_parse_rule(opt, ac);
		if (0 == rule_jmp)
			break ;
		if (0 == ft_option_compare("--", opt->argv[ac]))
		{
			++ac;
			break ;
		}
		ac += rule_jmp;
	}
	opt->argv += ac;
	opt->argc -= ac;
}
