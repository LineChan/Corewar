/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_location.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 17:48:39 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_lexer.h"

int		ft_print_location(t_lexer *lexer)
{
	ft_fprintf(ft_stderr, "\033[31m-[File: %s] - [LINE %d] [POS %d]\033[0m\n",
		lexer->loc.file, lexer->loc.line, lexer->loc.pos);
	++lexer->error;
	return (0);
}
