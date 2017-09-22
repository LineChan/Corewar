/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_mergesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:42:13 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

/*
 * Returns a list organized in an intermediate format suited
 * to chaining of merge() calls: null-terminated, no reserved or
 * sentinel head node, "prev" links not maintained.
 */
static t_list *merge(int (*cmp)( t_list *a, t_list *b),
                                t_list *a, t_list *b)
{
        t_list head, *tail = &head;

        while (a && b) {
                /* if equal, take 'a' -- important for sort stability */
                if ((*cmp)(a, b) <= 0) {
                        tail->next = a;
                        a = a->next;
                } else {
                        tail->next = b;
                        b = b->next;
                }
                tail = tail->next;
        }
        tail->next = a?a:b;
        return head.next;
}

#define LIST_DO				do {
#define LIST_WHILE(cond)	} while (cond)

/*
 * Combine final list merge with restoration of standard doubly-linked
 * list structure.  This approach duplicates code from merge(), but
 * runs faster than the tidier alternatives of either a separate final
 * prev-link restoration pass, or maintaining the prev links
 * throughout.
 */
static void merge_and_restore_back_links(
                                int (*cmp)( t_list *a,
                                        t_list *b),
                                t_list *head,
                                t_list *a, t_list *b)
{
        t_list *tail = head;
  /*      uint8_t count = 0;
*/
        while (a && b) {
                /* if equal, take 'a' -- important for sort stability */
                if ((*cmp)(a, b) <= 0) {
                        tail->next = a;
                        a->prev = tail;
                        a = a->next;
                } else {
                        tail->next = b;
                        b->prev = tail;
                        b = b->next;
                }
                tail = tail->next;
        }
        tail->next = a ? a : b;

        LIST_DO;
                tail->next->prev = tail;
                tail = tail->next;
        LIST_WHILE(tail->next);

        tail->next = head;
        head->prev = tail;
}

/*******************
 * list_sort - sort a list
 *
 * This function implements "merge sort", which has O(nlog(n))
 * complexity.
 *
 * head the list to sort
 * cmp the elements comparison function
 * 
 * The comparison function @cmp must return a negative value if @a
 * should sort before @b, and a positive value if @a should sort after
 * @b. If @a and @b are equivalent, and their original relative
 * ordering is to be preserved, @cmp must return 0.
 */
void list_sort( t_list *head,
                int (*cmp)( t_list *a,
                        t_list *b))
{
        t_list *part[0x32+1]; /* sorted partial lists
                                                -- last slot is a sentinel */
        int lev;  /* index into part[] */
        int max_lev = 0;
        size_t  k = 0;
        t_list *list;

        if (ft_list_is_empty(head))
                return;
            while (k < sizeof(part))
                part[k++] = 0;

        head->prev->next = NULL;
        list = head->next;

        while (list) {
                t_list *cur = list;
                list = list->next;
                cur->next = NULL;

                for (lev = 0; part[lev]; lev++) {
                        cur = merge(cmp, part[lev], cur);
                        part[lev] = NULL;
                }
                if (lev > max_lev) {
                        if ((lev >= LIST_SIZEOF_ARR(part)-1)) {
                                lev--;
                        }
                        max_lev = lev;
                }
                part[lev] = cur;
        }

        for (lev = 0; lev < max_lev; lev++)
                if (part[lev])
                        list = merge(cmp, part[lev], list);

        merge_and_restore_back_links(cmp, head, part[max_lev], list);
}

/*
** Linux mergesort. Need to re-write it
*/
void	ft_list_mergesort(t_list *list_head, int (*f)(t_list *a, t_list *b))
{
	list_sort(list_head, f);
}
