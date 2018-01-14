/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/25 13:17:34 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_PRIVATE_H
# define FT_CTYPE_PRIVATE_H

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
