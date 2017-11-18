/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/17 20:49:21 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"

t_token		*ft_lex_header(t_location *loc)
{
	t_token		*token;
	char const	*tmp;

	token = 0;
	/* Check for '.name' */
	if (0 == ft_strncmp(NAME_CMD_STRING, loc->pc, 5))
		token = ft_token_new(NAME_CMD_STRING, 5, TK_NAME, loc);
	/* Check for '.comment' */
	else if (0 == ft_strncmp(COMMENT_CMD_STRING, loc->pc, 8))
		token = ft_token_new(COMMENT_CMD_STRING, 8, TK_COMMENT, loc);
	/* Check for a strict "string" correctly formatted. */
	else if ('"' == loc->pc[0] && 0 != (tmp = ft_strchr(loc->pc + 1, '"')))
	{
		ft_lexer_relocate(loc, 1);
		token = ft_token_new(loc->pc, tmp - loc->pc, TK_STRING, loc);
		ft_lexer_relocate(loc, 1);
	}
	/* Return the correct token, or 0 */
	return (token);
}
