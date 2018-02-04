/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/03 17:53:53 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf.h"
#include "ft_asm.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

static char	*ft_loadfile(char const *file)
{
	char		*file_content;
	struct stat	st;
	int			fd;

	/* Check for valid suffix '.s' */
	if (*(uint16_t *)".s" != *(uint16_t *)(file + ft_strlen(file) - 2))
	{
		ft_fprintf(ft_stderr, "File {red:%s} is not a champion\n", file);
		return (0);
	}
	/* Check if file exist and get the length. */
	if (0 > stat(file, &st))
	{
		ft_fprintf(ft_stderr, "File {red:%s} does not exist\n", file);
		return (0);
	}
	/* Check if file is readable */
	fd = open(file, O_RDONLY);
	if (0 > fd)
	{
		ft_fprintf(ft_stderr, "Can't open file {red:%s}\n", file);
		return (0);
	}
	/* Alloc a string with the perfect size */
	file_content = ft_strnew(st.st_size + 1);
	/* Read the file into the string */
	read(fd, file_content, st.st_size);
	/* We can now close the file descriptor and return the file content */
	close(fd);
	return (file_content);
}

int 		main(int argc, char **argv)
{
	char	*file_content;
	int		dump;

	/* Check arguments */
	if (2 > argc)
	{
		ft_printf("Usage: \"%s [-a] <champion.s> [...]\"\n", argv[0]);
		ft_printf("        -a: Dump an annotated version\n");
		return (0);
	}


	dump = 0;
	if (0 == ft_strcmp("-a", argv[1]))
	{
		++argv;
		dump = 1;
	}
	/* For each arguments, run the loop. It allow us to compile
	   any champions passed as parameter */
	while (0 != *++argv)
	{
		/* Get the content of the input file */
		file_content = ft_loadfile(*argv);
		if (0 != file_content)
		{
			/* Compile the file */
			ft_asm(*argv, file_content, dump);
			/* Cleanup the memory */
			ft_strdel(&file_content);
		}
	}
	return (0);
}
