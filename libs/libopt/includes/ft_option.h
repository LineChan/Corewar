/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/30 19:41:20 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTION_H
# define FT_OPTION_H

# include <stddef.h>
# include <stdint.h>

/**
 * @brief	Get size of statically allocated array
 */
# define OPTION_SIZEOF_ARR(x)	((int)(sizeof(x) / sizeof(0[(x)])))

/**
 * @brief	Assert option-name has less than 64 chars
 */
# define OPTION_NAME_SIZE		64

/**
 * @brief	Assert option-data has less than 256 chars
 */
# define OPTION_DATA_SIZE		256

/**
 * @brief   Option pair containing name and data;
 */
typedef struct		s_option_list
{
	char			name[OPTION_NAME_SIZE];
	char			data[OPTION_DATA_SIZE];
}					t_option_list;

/**
 * @brief      Define options comportments
 */
typedef enum		e_option_key
{
	OPTION_KEY_BOOL = 0,
	OPTION_KEY_STRING
}					t_option_key;

/**
 * @brief      Option rule struct with name and key
 */
typedef struct		s_option_rule
{
	char			name[OPTION_NAME_SIZE + 1];
	t_option_key	key;
}					t_option_rule;

/**
 * @brief      Option struct
 * 
 * That structure handle options and command line arguments from main.
 * It allow you to define rules to parse argc/argv.
 */
typedef struct		s_option
{
	size_t			option_count;
	t_option_list	*option_list;
	size_t			rule_count;
	t_option_rule	*rule_list;
	int				argc;
	char			**argv;
}					t_option;

/**
 * @brief      Create new option structure using calloc.
 * 
 * details     Malloc errors aren't catched as long as the standards does not
 *             define these kind of behaviors.
 *              ==>> https://linux.die.net/man/3/malloc
 *              ==>> http://linuxfr.org/users/gouttegd/journaux/gestion-des-erreurs-d-allocation-memoire-en-c
 *
 * @param 	argc	main(argc, ...)
 * @param 	argv  	main(..., argv)
 *
 * @return     ft_option_new return a valid memory area cleared, or NULL.
 */
t_option			*ft_option_new(int argc, char **argv);

/**
 * @brief      Erase pointer
 *
 * @param      ptr   The pointer
 */
void				ft_option_del(t_option **ptr);

/**
 * @brief      Add rule to the option's rule list
 *
 * @param      opt	Option struct
 * @param      rule	Rule name (Ex: "--debug")
 * @param      opt	Rule key
 */
void				ft_option_add_rule(t_option *opt, char const *rule, t_option_key key);

/**
 * @brief      Find rule in rule_list
 * 
 * @details    Find operation is garanted to be O(logn)
 * 
 * @param 		opt	Option struct
 * @param 		option_name Name of the option we want the value
 *
 * @return     ft_option_find the valid founded data, or NULL.
 */
char				*ft_option_find(t_option *opt, char const *option_name);

/**
 * @brief      Argument parser
 * 
 * @details 	Argument parser can parse the following grammar:
 *           	"--toto"
 *           		==>>	{ "--toto", "true" }
 *           	"--toto titi"
 *           		==>>	{ "--toto", "titi" }
 *           	"--toto=titi"
 *           		==>>	{ "--toto", "titi" }
 *           		
 *           	Special symbol "--" abort parsing at current position
 *
 * @param      opt	Valid option struct
 */
void				ft_option_parse(t_option *opt);

/**
 * @brief      Tool function faking strcmp
 */
int					ft_option_compare(char const *s1, char const *s2);

/**
 * @brief      Tool function faking strcpy
 */
void				ft_option_copy(char const *from, char *to);

/**
 * @brief      Tool function faking strlen
 */
size_t				ft_option_size(char const *name);



/* Main

//make && gcc -L . -lopt -Iincludes main.c && ./a.out -l --toto=maman -a u -b x titi toto tutu
//make && gcc -L . -lopt -Iincludes main.c && ./a.out -l --toto maman -a u -b x titi toto tutu

#include "ft_option.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_option	*opt;
	size_t		i;

	opt = ft_option_new(argc, argv);
	ft_option_add_rule(opt, "-l", OPTION_KEY_BOOL);
	ft_option_add_rule(opt, "--toto", OPTION_KEY_STRING);
	ft_option_add_rule(opt, "-d", OPTION_KEY_STRING);
	ft_option_add_rule(opt, "-e", OPTION_KEY_STRING);
	ft_option_add_rule(opt, "-c", OPTION_KEY_STRING);
	ft_option_add_rule(opt, "-b", OPTION_KEY_STRING);
	ft_option_add_rule(opt, "-a", OPTION_KEY_STRING);
	ft_option_parse(opt);


	printf("opt == %d [%zu, %zu]\n", opt == 0, opt->option_count, opt->rule_count);
	printf("-->> %d", opt->argc);
	if (opt->argc > 0) printf(" -> %s .. %s\n", opt->argv[0], opt->argv[opt->argc - 1]);
	else printf("\n");

	i = 0;
	while (i < opt->option_count)
	{
		printf("OPT(%s): \"%s\"\n", opt->option_list[i].name, opt->option_list[i].data);
		++i;
	}

	printf("[%s]\n", ft_option_find(opt, "--toto"));
	printf("[%s]\n", ft_option_find(opt, "-a"));

	ft_option_del(&opt);
	printf("opt == %d\n", opt == 0);
	return (0);
}
*/




#endif
