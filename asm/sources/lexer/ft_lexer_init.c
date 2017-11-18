/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/15 08:19:05 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"

static int	ft_lexer_init_split(int const c)
{
	return ('\n' == c);
}

void	ft_lexer_init(t_lexer *lexer, char const *file, char const *file_content)
{
	ft_memset(&lexer->loc, 0, sizeof(lexer->loc));
	lexer->loc.tab = ft_strsplit(file_content, &ft_lexer_init_split);
	INIT_LIST_HEAD(lexer->token_head);
	lexer->loc.pc = file_content;
	lexer->loc.file = file;
}
