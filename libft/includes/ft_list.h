/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/29 00:35:55 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>
# include <stdint.h>

/**
 * @brief	Get size of statically allocated array
 */
# define LIST_SIZEOF_ARR(x)			((int)(sizeof(x) / sizeof(0[(x)])))

/**
 * @brief	Linux-like linked list
 *	 ==> https://github.com/torvalds/linux/blob/master/include/linux/list.h
 */
typedef struct		s_list
{
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/**
 * @brief	Init list nodes, compatible -ansi -pedantic
 */
# define INIT_LIST_HEAD(x)	(x).next = (x).prev = &(x)

/**
 * @brief	Get offset of member, simulating struct at 0.
 */
# define OFFSETOF(st, m) 	((uint32_t)(&(((st *)0)->m)))

/**
 * @brief	Jump to the list container, using offsetof
 */
# define CONTAINEROF(ptr, st, m)	((st *)((int8_t *)(ptr) - OFFSETOF(st, m)))

/**
 * @brief Insert node in list
 * 
 * @param new  Node to insert in list
 * @param head List head
 */
void				ft_list_add(t_list *new, t_list *head);

/**
 * @brief Push node in list
 * 
 * @param new Node to push in list
 * @param head List head
 */
void				ft_list_add_tail(t_list *new, t_list *head);

/**
 * @brief Apply `func` on each node in list in safe mode.
 * 
 * @param head List head
 * @param func Function pointer
 */
void				ft_list_apply(t_list *head, void (*func)(t_list *));

/**
 * @brief Apply `func` on each node in list in safe mode in reverse order.
 * 
 * @param head List head
 * @param func Function pointer
 */
void				ft_list_apply_tail(t_list *head, void (*func)(t_list *));

/**
 * @brief Apply `func(data)` on each node in list in safe mode.
 * 
 * @param head List head
 * @param data Pointer to pass to the function pointer
 * @param func Function pointer
 */
void				ft_list_apply_data(t_list *head, void *data, void (*func)(t_list *, void *));

/**
 * @brief Unlink node
 * 
 * @param node Node to unlink
 */
void				ft_list_del(t_list *node);

/**
 * @brief Check if a list is empty
 * 
 * @param head List head
 * @return  1 if list is empty, otherwise 0
 */
int					ft_list_is_empty(t_list *head);

/**
 * @brief Check if a list contain only one node
 * 
 * @param head List head
 * @return  1 if list is singular, otherwise 0
 */
int					ft_list_is_singular(t_list *head);

/**
 * @brief Swap 2 nodes
 * 
 * @param node_a First node to swap
 * @param node_b Second node to swap
 */
void				ft_list_swap(t_list *node_a, t_list *node_b);

/**
 * @brief Find item in list (using `next` pointer)
 * 
 * @param head List head
 * @param func Function pointer
 * @return  First item found by `func`
 */
t_list				*ft_list_find(t_list *head, int (*func)(t_list *));
t_list				*ft_list_find_data(t_list *head, void const *data,
										int (*func)(t_list *, void const *));

/**
 * @brief Find item in list (using `prev` pointer)
 * 
 * @param head List head
 * @param func Function pointer
 * @return  First item found by `func`
 */
t_list				*ft_list_find_tail(t_list *head, int (*func)(t_list *));
t_list				*ft_list_find_tail_data(t_list *head, void const *data,
										int (*func)(t_list *, void const *));

/**
 * @brief Count nodes in list
 * 
 * @param head List head
 * @return	Size of list
 */
size_t				ft_list_len(t_list *head);

/**
 * @brief Unlink node and insert to head
 * 
 * @param node Node to insert
 * @param head List head
 */
void				ft_list_move(t_list *node, t_list *head);

/**
 * @brief Unlink node and push it to list
 * 
 * @param node Node to push
 * @param head List head
 */
void				ft_list_move_tail(t_list *node, t_list *head);

/**
 * @brief Insert sublist `src` in list `dst`
 * 
 * @param fsrc First node of sublist to insert in list
 * @param lsrc Last node of sublist to insert in list
 * @param dst List head destionation
 */
void				ft_list_move_sub(t_list *fsrc, t_list *lsrc, t_list *dst);


/**
 * @brief	Sorting algorithms types
 *
 * @details
 * 			    	+-----------+-----------+-----------+--------+
 *    			 	|   Best 	|   Worse 	|  Average	| Stable |
 * +----------------+-----------+-----------+-----------+--------+
 * | Mergesort  	|  nlog(n)	|  nlog(n)	|  nlog(n)	|  Yes	 |
 * +----------------+-----------+-----------+-----------+--------+
 * | Bubblesort 	|	  n		|	 n*n	|	 n*n	|  Yes	 |
 * +----------------+-----------+-----------+-----------+--------+
 * | Insertion sort	|	  n		|	 n*n	|	 n*n	|  Yes	 |
 * +----------------+-----------+-----------+-----------+--------+
 * | Selection sort |	 n*n	|	 n*n	|	 n*n	|   No	 |
 * +----------------+-----------+-----------+-----------+--------+
 */

/**
 * @brief	Merge sort
 * 
 * @details
 *	==> http://lxr.free-electrons.com/source/lib/list_sort.c
 *
 * @param list_head	List to sort
 * @param fcmp Compare-function pointer
 */
void	ft_list_mergesort(t_list *list_head, int (*fcmp)(t_list *, t_list *));

/**
 * @brief	Bubble sort
 *
 * @param list_head	List to sort
 * @param fcmp Compare-function pointer
 */
void	ft_list_bubblesort(t_list *list_head, int (*fcmp)(t_list *, t_list *));

/**
 * @brief	Insertion sort
 *
 * @param list_head	List to sort
 * @param fcmp Compare-function pointer
 */
void	ft_list_insertsort(t_list *list_head, int (*fcmp)(t_list *, t_list *));

/**
 * @brief	Selection sort
 *
 * @param list_head	List to sort
 * @param fcmp Compare-function pointer
 */
void	ft_list_selectsort(t_list *list_head, int (*fcmp)(t_list *, t_list *));

#endif
