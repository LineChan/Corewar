/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:04:44 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/20 16:47:36 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

/*
** Standard libraries
*/
# include <stdlib.h>

/*
** Number of bits and mask sign
*/
# define NB_BIT 8
# define MASK_SIGN ((sizeof(int) * NB_BIT) - 1)

/*
** Functions
*/
# define SWAP(x,y) (x ^= y ^= x ^= y)
# define ABS(x) ((x + (x >> MASK_SIGN)) ^ (x >> MASK_SIGN))
# define SIZEOF_TAB(x) (sizeof(x)/sizeof(x[0]))
# define EXIT_FAIL(x) ft_printf("{red:%s}\n",x), exit(EXIT_FAILURE)

/*
** Returns 1 if a and b have opposite signs
*/
# define OP_SIGN(x,y) ((x ^ y) < 0)

/*
** Returns 1 if x is negative ( looking at the far left bit )
*/
# define IS_NEG(x) ((unsigned int)x >> MASK_SIGN)

/*
** Returns the minimum or the max of two int without branching
** (INT_MIN <= x - y <= INT_MAX)
*/
# define MIN(x,y) (y + ((x - y) & ((x - y) >> MASK_SIGN)))
# define MAX(x,y) (x - ((x - y) & ((x - y) >> MASK_SIGN)))

/*
** Returns 1 if the number is a power of 2
*/
# define POW_OF_TWO(x) (x && (!(x & (x - 1))))

#endif
