/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:11:33 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/20 19:13:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include "ft_vm.h"

/*
** Splits a text according to a token
**
** ft_gnl :
** 1st parameter : file descriptor
** 2nd parameter : token
**
** ft_fgnt :
**
** 1st parameter : text to read
** 2nd parameter : token
*/

static int				ft_gnt_precheck(char *buff,
								const char token,
								char **line)
{
	char			*ptr;

	if ((ptr = ft_strchr(buff, token)))
		*ptr++ = '\0';
	if (!(*line = ft_strdup(buff)))
		return (-1);
	if (ptr)
	{
		ft_memmove(buff, ptr, ft_strlen(ptr) + 1);
		return (1);
	}
	ft_memset(buff, '\0', GNT_SIZE);
	return (0);
}

static int				ft_gnt_postcheck(char *buff,
								const char token,
								char **line)
{
	char			*ptr;
	char			*tmp;
	size_t			len;

	if ((ptr = ft_strchr(buff, token)))
		*ptr++ = '\0';
	tmp = *line;
	len = ft_strlen(*line);
	if (!(*line = ft_strnew(len + ft_strlen(buff))))
	{
		free(tmp);
		return (-1);
	}
	ft_strcpy(*line, tmp);
	ft_strcpy(*line + len, buff);
	free(tmp);
	tmp = 0;
	if (ptr != 0)
	{
		ft_memmove(buff, ptr, ft_strlen(ptr) + 1);
		return (1);
	}
	ft_memset(buff, '\0', GNT_SIZE);
	return (0);
}

static int				get_next_token(const int fd,
								const char token,
								char **line)
{
	static char		buff[GNT_SIZE + 1];
	int				ret;

	if (0 == line || fd < 0)
		return (-1);
	ret = ft_gnt_precheck(buff, token, line);
	if (0 == ret)
	{
		while ((ret = read(fd, buff, GNT_SIZE)))
		{
			if (0 > ret)
			{
				free(*line);
				*line = 0;
				return (-1);
			}
			buff[ret] = '\0';
			if ((ret = ft_gnt_postcheck(buff, token, line)))
				return (ret);
		}
		ret = (0 != **line);
	}
	return (ret);
}

char					*ft_gnt(const int fd, const char token)
{
	static char		*line;
	int				ret;

	if (IS_NEG(fd))
		EXIT_FAIL("FT_GNT : wrong file descriptor");
	if (!ft_isascii(token))
		EXIT_FAIL("FT_GNT : token is not an ascii");
	if (line)
	{
		free(line);
		line = 0;
	}
	ret = get_next_token(fd, token, &line);
	if (IS_NEG(ret))
		return (0);
	if (0 == ret && 0 != line && 0 == *line)
	{
		free(line);
		line = 0;
	}
	return (line);
}

char					*ft_fgnt(const char *file, const char token)
{
	static char		*line;
	static int		fd;
	int				ret;

	if (!line)
	{
		if (IS_NEG((fd = open(file, O_RDONLY))))
			EXIT_FAIL("FT_GNT : wrong file descriptor");
	}
	else
	{
		free(line);
		line = 0;
	}
	ret = get_next_token(fd, token, &line);
	if ((IS_NEG(ret)) && close(fd))
		return (0);
	if (!ret && line && !*line)
	{
		free(line);
		line = 0;
		close(fd);
	}
	return (line);
}
