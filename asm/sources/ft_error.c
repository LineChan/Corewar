/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/17 20:55:19 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"
# include "ft_printf.h"
# include "ft_ctype.h"
# include <unistd.h>
# include <stdarg.h>

static void	ft_print_marker(char const *line, char const *p, t_token *token)
{
	char const	*name;

	while (line != p)
	{
		write(ft_stderr, " ", 1);
		++line;
	}
	name = token->data->str + 1;
	ft_fprintf(ft_stderr, "{bgreen}^");
	while (0 != *name++)
		ft_fprintf(ft_stderr, "~");
	ft_fprintf(ft_stderr, "{none}\n");
}

int			ft_error(t_location *loc, t_token *token, char const *format, ...)
{
	char	tmp[1 << 12];
	char	*line;
	char	*p;
	va_list	ap;

	++loc->error;
	va_start(ap, format);
	ft_vsprintf(tmp, format, ap);
	va_end(ap);
	if (0 == token)
	{
		ft_fprintf(ft_stderr, "{bold:%s}", tmp);
		return (0);
	}
	ft_fprintf(ft_stderr, "{bold:%s:%d:%d:} {bred:error:} {bold:%s}",
		token->loc.file, token->loc.line, token->loc.pos, tmp);
	line = loc->tab[token->loc.line - 1];
	p = ft_strstr(line, token->data->str);
	if (0 != p)
	{
		write(ft_stderr, line, p - line);
		ft_fprintf(ft_stderr, "{bred:%s}", token->data->str);
		ft_fprintf(ft_stderr, "%s\n", p + token->data->len);
		ft_print_marker(line, p, token);
	}
	return (0);
}
