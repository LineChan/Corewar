/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/02 02:04:18 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTION_H
# define FT_OPTION_H

# include "ft_list.h"
#include <stdio.h>

/**
 * @brief	Get size of statically allocated array
 */
# define OPTION_SIZEOF_ARR(x)	((int)(sizeof(x) / sizeof(0[(x)])))

/**
 * @brief	Assert option-data has less than 256 chars
 */
# define OPTION_DATA_SIZE		256

/**
 * @brief   Option pair containing name and data;
 */
typedef struct		s_option_list
{
	char			*name;
	char			*data;
	t_list			list;
}					t_option_list;

# define C_OPTION(it)	CONTAINEROF(it, t_option_list, list)

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
	char			*name;
	t_option_key	key;
	t_list 			list;
}					t_option_rule;

# define C_RULE(it)		CONTAINEROF(it, t_option_rule, list)

/**
 * @brief      Option struct
 * 
 * That structure handle options and command line arguments from main.
 * It allow you to define rules to parse argc/argv.
 */
typedef struct		s_option
{
	t_list			option_head;
	t_list			rule_head;
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
