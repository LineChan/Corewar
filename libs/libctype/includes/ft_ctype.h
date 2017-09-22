/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:36:26 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

/**
 * @brief       Checks for an alphabetic character in the
 * 				standard "C" locale, it is equivalent to
 * 				(ft_isupper || ft_islower).
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_isalpha return 1 on success, otherwhise 0.
 */
int     		ft_isalpha(int c);

/**
 * @brief       Checks for an alphanumeric characters; it
 * 				is equivalent to (ft_isalpha || ft_isdigit)
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_isalnum return 1 on success, otherwhise 0.
 */
int     		ft_isalnum(int c);

/**
 * @brief       Checks whether c is a 7-bit unsigned char value
 *				that fits into the ASCII character set.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_isascii return 1 on success, otherwhise 0.
 */
int     		ft_isascii(int c);

/**
 * @brief       Checks for a control character.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_iscntrl return 1 on success, otherwhise 0.
 */
int     		ft_iscntrl(int c);

/**
 * @brief       Checks for a digit ('0' through '9').
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_isdigit return 1 on success, otherwhise 0.
 */
int     		ft_isdigit(int c);

/**
 * @brief       Checks for a lower-case character.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_islower return 1 on success, otherwhise 0.
 */
int     		ft_islower(int c);

/**
 * @brief       Checks for an upper-case character.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_isupper return 1 on success, otherwhise 0.
 */
int     		ft_isupper(int c);

/**
 * @brief       Checks for any printable character except space.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_isgraph return 1 on success, otherwhise 0.
 */
int     		ft_isgraph(int c);

/**
 * @brief       Checks for any printable character including space.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_isprint return 1 on success, otherwhise 0.
 */
int     		ft_isprint(int c);

/**
 * @brief       Checks for any printable character which is not
 *				a space or an alphanumeric character.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_ispunct return 1 on success, otherwhise 0.
 */
int     		ft_ispunct(int c);

/**
 * @brief       Checks for white-space characters. In the "C"
 *				and "Posix" locales, these are: space, from-feed,
 *				newline, carriage return, horizontal tab and
 *				vertical tab.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_isspace return 1 on success, otherwhise 0.
 */
int     		ft_isspace(int c);

/**
 * @brief       Checks for a blank character; that is,
 *				a space or a tab. This function is a GNU
 *				extension.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_isblank return 1 on success, otherwhise 0.
 */
int     		ft_isblank(int c);

/**
 * @brief       Checks for a hexadecimal digits, i.e. one of
 * 				0 1 2 3 4 5 6 7 8 9 a A b B c C d D e E f F.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_isxdigit return 1 on success, otherwhise 0.
 */
int     		ft_isxdigit(int c);

/**
 * @brief       Converts the letter c to lower-case, if possible.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_tolower return a lower-case character of c.
 */
int     		ft_tolower(int c);

/**
 * @brief       Converts the letter c to upper-case, if possible.
 *
 * @param c		Fully promoted type of an unsigned char
 * @return 		ft_toupper return an upper-case character of c.
 */
int     		ft_toupper(int c);

/**
 * @brief		List of ctype possible flags.
 */
typedef enum	e_ctype_flags
{
	FT_CTYPE_ALIASING = 0,		/*!< Aliasing		*/
	FT_CTYPE_ISALPHA,			/*!< ft_isalpha		*/
	FT_CTYPE_ISALNUM,			/*!< ft_isalnum		*/
	FT_CTYPE_ISASCII,			/*!< ft_isascii		*/
	FT_CTYPE_ISCNTRL,			/*!< ft_iscntrl		*/
	FT_CTYPE_ISDIGIT,			/*!< ft_isdigit		*/
	FT_CTYPE_ISLOWER,			/*!< ft_islower		*/
	FT_CTYPE_ISUPPER,			/*!< ft_isupper		*/
	FT_CTYPE_ISGRAPH,			/*!< ft_isgraph		*/
	FT_CTYPE_ISPRINT,			/*!< ft_isprint		*/
	FT_CTYPE_ISPUNCT,			/*!< ft_ispunct		*/
	FT_CTYPE_ISSPACE,			/*!< ft_isspace		*/
	FT_CTYPE_ISBLANK,			/*!< ft_isblank		*/
	FT_CTYPE_ISXDIGIT			/*!< ft_isxdigit	*/
}				t_ctype_flags;

/**
 * @brief       Private engine of ctype.h using a pre-computed table.
 *
 * @param c		Fully promoted type of an unsigned char
 * @param flag	Flag to test
 * @return 		1 on success, otherwhise 0.
 */
int     		ft_ctype_mask(int c, int flag);

#endif
