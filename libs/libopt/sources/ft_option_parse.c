/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/02 02:08:01 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_string.h"
#include <stdlib.h>

static void	ft_option_insert(t_option *opt, char const *name, char const *data)
{
	t_option_list	*node;
	node = (t_option_list *)ft_memalloc(sizeof(t_option_list));
	node->name = ft_strdup(name);
	node->data = ft_strdup(data);
	ft_list_add_tail(&node->list, &opt->option_head);
}

static int	ft_option_rule(t_option *opt, int ac, t_option_key key, char const *sub)
{
	if (key == OPTION_KEY_BOOL)
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
	t_list	*it;
	size_t	len;
	char	*arg;
	char	*sub;

	sub = 0;
	it = opt->rule_head.next;
	while (it != &opt->rule_head)
	{
		arg = opt->argv[ac];
		len = ft_strlen(C_RULE(it)->name);
		if (ft_strlen(arg) > len && '=' == arg[len])
		{
			arg[len] = 0;
			sub = arg + len + 1;
		}
		if (0 == ft_strcmp(arg, C_RULE(it)->name))
			return (ft_option_rule(opt, ac, C_RULE(it)->key, sub));
		if (0 != sub)
			arg[len] = '=';
		it = it->next;
		sub = 0;
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
		if (0 == ft_strcmp("--", opt->argv[ac]))
		{
			++ac;
			break ;
		}
		ac += rule_jmp;
	}
	opt->argv += ac;
	opt->argc -= ac;
}
