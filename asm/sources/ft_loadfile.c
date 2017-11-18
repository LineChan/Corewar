/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/12 21:45:38 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf.h"
#include "ft_asm.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_loadfile(char const *file)
{
	char		*file_content;
	struct stat	st;
	int			fd;

	/* Check for valide suffix '.s' */
	if (*(uint16_t *)".s" != *(uint16_t *)(file + ft_strlen(file) - 2))
	{
		ft_fprintf(ft_stderr, "File {red:%s} is not a champion\n", file);
		return (0);
	}
	/* Check if file exist */
	if (0 > stat(file, &st))
	{
		ft_fprintf(ft_stderr, "File {red:%s} does not exist\n", file);
		return (0);
	}
	/* Check if file is readable */
	fd =  open(file, O_RDONLY);
	if (0 > fd)
	{
		ft_fprintf(ft_stderr, "Can't open file {red:%s}\n", file);
		return (0);
	}
	/* Read file content */
	file_content = ft_strnew(st.st_size);
	read(fd, file_content, st.st_size);
	close(fd);
	return (file_content);
}
