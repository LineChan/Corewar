/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/18 15:29:57 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_log.h"
#include <assert.h>
#include <time.h>

int		ft_log(char const *format, ...)
{
	extern int	g_log_fd;
	int 		count;
	va_list		ap;

	/* If logger_fd is not initialised, or if the initialisation failed,
	   we set the destination file descriptor as stdout. */
	if (0 > g_log_fd)
		g_log_fd = ft_stdout;
	/* Print date with actual timestamp in lowercase */
	count = ft_fprintf(g_log_fd, "[%k] -- ", time(0));
	
	/* Print the actual message the used wanted to print */
	va_start(ap, format);
	count += ft_vfprintf(g_log_fd, format, ap);
	va_end(ap);

	/* Return total count of character printed */
	return (count);
}
