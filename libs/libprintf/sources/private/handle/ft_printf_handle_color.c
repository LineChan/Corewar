/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:48:51 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/14 19:32:53 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"
#include "ft_string.h"
#include <ctype.h>
#include <time.h>

#define PRINTF_COLOR_STACK	2048
#define PRINTF_PC 			(*ft_print_color_stack_pointer())		

static char const			*g_color_stack[PRINTF_COLOR_STACK + 1] = { 0 };

static char const * const g_color_def[] =
{
	"{none}", "\033[0m",
	"{bold}", "\033[1m",
	"{black}", "\033[30m",
	"{red}", "\033[31m",
	"{green}", "\033[32m",
	"{yellow}", "\033[33m",
	"{blue}", "\033[34m",
	"{pink}", "\033[35m",
	"{magenta}", "\033[35m",
	"{cyan}", "\033[36m",
	"{bblack}", "\033[30;1m",
	"{bred}", "\033[31;1m",
	"{bgreen}", "\033[32;1m",
	"{byellow}", "\033[33;1m",
	"{bblue}", "\033[34;1m",
	"{bpink}", "\033[35;1m",
	"{bmagenta}", "\033[35;1m",
	"{bcyan}", "\033[36;1m",
};

static char const * const g_color_def_2[] =
{
	"{none:", "\033[0m",
	"{bold:", "\033[1m",
	"{black:", "\033[30m",
	"{red:", "\033[31m",
	"{green:", "\033[32m",
	"{yellow:", "\033[33m",
	"{blue:", "\033[34m",
	"{pink:", "\033[35m",
	"{magenta:", "\033[35m",
	"{cyan:", "\033[36m",
	"{bblack:", "\033[30;1m",
	"{bred:", "\033[31;1m",
	"{bgreen:", "\033[32;1m",
	"{byellow:", "\033[33;1m",
	"{bblue:", "\033[34;1m",
	"{bpink:", "\033[35;1m",
	"{bmagenta:", "\033[35;1m",
	"{bcyan:", "\033[36;1m",
};

static int		*ft_print_color_stack_pointer(void)
{
	static int	stack_pointer = 0;

	return (&stack_pointer);
}

static int		ft_printf_handle_color_rbracket(char **p, char const **format)
{
	if ('}' == **format && 0 != PRINTF_PC && '\\' != (*format)[-1])
	{
		g_color_stack[PRINTF_PC] = 0;
		PRINTF_PC -= 1;
		*p = ft_stpcpy(*p, g_color_stack[PRINTF_PC]);
		*format += 1;
		return (1);
	}
	return (0);
}

static int		ft_printf_handle_color_lbracket(char **p, char const **format)
{
	size_t		len;
	size_t		i;

	i = 0;
	g_color_stack[0] = "\033[0m";
	while (i < (sizeof(g_color_def_2) / sizeof(g_color_def_2[0])))
	{
		len = ft_strlen(g_color_def_2[i]);
		if (0 == ft_strncmp(*format, g_color_def_2[i], len))
		{
			if (PRINTF_PC < PRINTF_COLOR_STACK)
				PRINTF_PC += 1;
			g_color_stack[PRINTF_PC] = g_color_def_2[i + 1];
			*p = ft_stpcpy(*p, g_color_stack[PRINTF_PC]);
			*format += len;
			return (1);
		}
		i += 2;
	}
	return (0);

}

int				ft_printf_handle_color(char **p, char const **format)
{
	size_t		len;
	size_t		i;

	if (0 != ft_printf_handle_color_lbracket(p, format))
		return (1);
	if (0 != ft_printf_handle_color_rbracket(p, format))
		return (1);
	i = 0;
	while (i < (sizeof(g_color_def) / sizeof(g_color_def[0])))
	{
		len = ft_strlen(g_color_def[i]);
		if (0 == ft_strncmp(*format, g_color_def[i], len))
		{
			*p = ft_stpcpy(*p, g_color_def[i + 1]);
			*format += len;
			return (1);
		}
		i += 2;
	}
	return (0);
}
