/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/20 01:04:38 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_string.h"
#include <stdlib.h>

static void	ft_option_update(t_option_list *node, char const *data)
{
	char	**tmp;
	size_t	i;

	tmp = (char **)ft_memalloc((node->nb_data + 2u) * sizeof(char *));
	i = 0;
	while (i < node->nb_data)
	{
		tmp[i] = node->data[i];
		++i;
	}
	tmp[i] = ft_strdup(data);
	tmp[i + 1] = 0;
	free(node->data);
	node->data = tmp;
	++node->nb_data;
}

static void	ft_option_insert(t_option *opt, char const *name, char const *data)
{
	t_option_list	*node;
	t_list			*it;

	it = opt->option_head.next;
	while (it != &opt->option_head)
	{
		node = C_OPTION(it);
		if (0 == ft_strcmp(node->name, name))
		{
			ft_option_update(node, data);
			return ;
		}
		it = it->next;
	}
	node = (t_option_list *)ft_memalloc(sizeof(t_option_list));
	node->name = ft_strdup(name);
	node->nb_data = 1;
	node->data = (char **)ft_memalloc((node->nb_data + 1u) * sizeof(char *));
	node->data[0] = ft_strdup(data);
	node->data[1] = 0;
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
