/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/16 23:25:56 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "ft_lexer.h"
# include "ft_ctype.h"
# include "ft_string.h"

static int	ft_lexer_skip(t_location *loc)
{
	/* Skip tout les espaces/tabultations */
	if (0 != ft_isspace(loc->pc[0]) && '\n' != loc->pc[0])
	{
		ft_lexer_relocate(loc, 1);
		while (0 != ft_isspace(loc->pc[0]) && '\n' != loc->pc[0])
			ft_lexer_relocate(loc, 1);
		return (1);
	}
	/* commentaire: skip tout jusqu'a la prochaine ligne */
	if (COMMENT_CHAR == loc->pc[0] || ';' == loc->pc[0])
	{
		++loc->pc;
		while (0 != loc->pc[0] && '\n' != loc->pc[0])
			++loc->pc;
		return (1);
	}
	return (0);
}

static const	t_lex_rule	g_lex_rule[] =
{
	&ft_lex_header, 
	&ft_lex_label,
	&ft_lex_word,
	&ft_lex_reg,
	&ft_lex_dir,
	&ft_lex_ind
};

t_token		*ft_lexer_read(t_lexer *lexer)
{
	t_token		*p;
	size_t		i;

	/* Keep skipping every known pattern */
	while (0 != ft_lexer_skip(&lexer->loc))
		continue ;
	/* Try every lexing rules functions */
	i = 0;
	while (i < sizeof(g_lex_rule) / sizeof(g_lex_rule[0]))
	{
		p = g_lex_rule[i](&lexer->loc);
		if (0 != p)
		{
			ft_list_add_tail(&p->list, &lexer->token_head);
			return (p);
		}
		++i;
	}
	return (0);
}
