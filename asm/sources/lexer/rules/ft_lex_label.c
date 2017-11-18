/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/12 21:18:07 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"
# include "ft_ctype.h"
# include "ft_printf.h"

t_token		*ft_lex_label(t_location *loc)
{
	t_token		*token;
	char const	*p;

	token = 0;
	/* Check for characters that we know:
		lower, digit or underscore, as many as possible. */
	p = loc->pc;
	while (0 != ft_strchr(LABEL_CHARS, *p))
		++p;
	/* Check for the last special char */
	if (loc->pc < p && LABEL_CHAR == *p)
	{
		token = ft_token_new(loc->pc, p - loc->pc, TK_LABEL, loc);
		/* skip last ':' LABEL_CHAR */
		ft_lexer_relocate(loc, 1);
	}
	return (token);
}
