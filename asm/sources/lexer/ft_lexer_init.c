/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 16:01:19 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"

void		ft_lexer_init(t_lexer *lexer, char const *file, char const *content)
{
	ft_memset(&lexer->loc, 0, sizeof(lexer->loc));
	INIT_LIST_HEAD(lexer->token_head);
	/* Pc start on start of file content */
	lexer->loc.pc = content;
	lexer->loc.file = file;
}
