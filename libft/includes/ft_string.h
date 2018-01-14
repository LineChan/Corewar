/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/03 13:21:13 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdint.h>
# include <stddef.h>

/**
 * \brief   Define PATH_MAX from linux/MacOS
 */
# define FT_PATH_MAX        (1 << 12)

/**
 * \brief	LIBSTR_TYPE is a new type created to manipulate strings over loops.
 */
# define LIBSTR_TYPE		uint32_t

/**
 * \brief   Detect the NUL byte in LIBSTR_TYPE
 */
# define DETECTNULL(x)		(((x) - 0x01010101) & ~(x) & 0x80808080)

/**
 * \brief   Detect a specific bytes in a LIBSTR_TYPE
 */
# define DETECTCHAR(x, y)	(DETECTNULL((x) ^ (y)))

/**
 * \brief   Convert a byte to a LIBSTR_TYPE.
 * 			0x1a is converted to 0x1a1a1a1a
 */
# define LIBSTR_WORD(x)		((x) | ((x) << 8) | ((x) << 16) | ((x) << 24))

/**
 * \brief   Return true if p is aligned on b bytes, otherwise 0.
 */
# define ALIGNED(p, b)		(!(((uintptr_t)(void const *)(p)) & ((b) - 1)))

/**
 * @brief      Malloc wrapper
 * 
 * details     Malloc errors aren't catched as long as the standards does not
 *             define these kind of behaviors.
 *              ==>> https://linux.die.net/man/3/malloc
 *              ==>> http://linuxfr.org/users/gouttegd/journaux/gestion-des-erreurs-d-allocation-memoire-en-c
 *
 * @param      size  The size
 *
 * @return     ft_memalloc return a valid memory area cleared, or NULL.
 */
void    	*ft_memalloc(size_t size);
void		*ft_calloc(size_t nb, size_t size);

# define ALLOC(t, n)	(t *)ft_calloc((n), sizeof(t))

/**
 * @brief      Erase pointer and reset to 0
 *
 * @param      ptr   The pointer
 */
void    	ft_memdel(void **ptr);

/**
 * @brief      Fill a byte string with a byte value
 *
 * details     The ft_memset() function writes n bytes of
 * 			   value c (converted to an unsigned char) to
 * 			   the string p.
 *
 * @param      p     String
 * @param      c     Value, which is converted to unsigned char
 * @param      len   Number of bytes
 *
 * @return     The ft_memset() function returns its first argument.
 */
void    	*ft_memset(void *p, int c, size_t len);

/**
 * @brief      Copy memory area
 * 
 * details     The ft_memcpy() function copies n bytes
 * 			   from memory area src to memory area dst.
 *       	   If dst and src overlap, behavior is undefined.
 *       	   Applications in which dst and src might
 *       	   overlap should use ft_memmove() instead.
 *
 * @param      dst   The destination
 * @param      src   The source
 * @param      len	 The length
 *
 * @return     The ft_memcpy() function returns the original value of dst.
 */
void    	*ft_memcpy(void *dst, void const *src, size_t len);

/**
 * @brief      Copy string until character found
 *
 * details     The ft_memccpy() function copies bytes from
 * 			   string src to string dst. The source and
 * 			   destination strings should not overlap, as
 * 			   the behavior is undefined.
 *
 * @param      dst      The destination
 * @param      src      The source
 * @param      endchar  The endchar
 * @param      len      The length
 *
 * @return     If the character c (as converted to an unsigned char)
 *             occurs in the string src, the copy stops and a pointer
 *       	   to the byte after the copy of c in the string dst is
 *       	   returned. Otherwise, n bytes are copied, and a NULL
 *       	   pointer is returned.
 */
void    	*ft_memccpy(void *dst, void const *src, int endchar, size_t len);

/**
 * @brief      Copy memory area
 *
 * details     The ft_memmove() function copies len bytes from string
 * 			   src to string dst. The two strings may overlap; the copy
 * 			   is always done in a non-destructive manner.
 *
 * @param      dst   The destination
 * @param      src   The source
 * @param      len   The length
 *
 * @return     The ft_memmove() function returns the original value of dst.
 */
void    	*ft_memmove(void *dst, void const *src, size_t len);

/**
 * @brief      Compare two memory areas
 *
 * details     The ft_memcmp() function compares byte string s1 against
 * 			   byte string s2. Both strings are assumed to be len bytes
 * 			   long.
 *
 * @param      s1    The first memory area
 * @param      s2    The second memory area
 * @param      len   The length
 *
 * @return     The ft_memcmp() function returns zero if the two strings
 *             are identical, otherwise returns the difference between
 *             the first two differing bytes (treated as unsigned char
 *             values, so that `\200' is greater than `\0', for example).
 *             Zero-length strings are always identical.  This behavior
 *             is not required by C and portable code should only depend
 *             on the sign of the returned value.
 */
int     	ft_memcmp(void const *s1, void const *s2, size_t len);

/**
 * @brief      Locate byte in memory area
 * 
 * details     The ft_memchr() function locates the first occurrence of c
 * 			   (converted to an unsigned char) in memory area m.
 *
 * @param      m     The memory area
 * @param      c     The byte to locate
 * @param      len   The length
 *
 * @return     The ft_memchr() function returns a pointer to the byte
 *             located, or NULL if no such byte exists within n bytes.
 */
void    	*ft_memchr(void const *m, int c, size_t len);

/**
 * @brief      todo
 *
 * @param      a     { parameter_description }
 * @param      b     { parameter_description }
 * @param[in]  len   The length
 */
void		ft_memswap(void *a, void *b, size_t len);

/**
 * @brief     Quicksort
 * 
 * @details   The  ft_qsort() function  sort an  array of nel
 *            objects, the initial member of which is pointed
 *            to by base. The size of each object is specified
 *            by width. The contents of the array base are
 *            sorted in ascending order according to a comparison
     		  function pointed to by compar, which requires
     		  two arguments pointing to the objects being compared.
 *
 * @param      base   The base to sort
 * @param[in]  nel    The number of element
 * @param[in]  width  The size of element
 * @param[in]  fcmp   The compare function
 */
void		ft_qsort(
						void *base,
						size_t nel,
						size_t width,
						int (*fcmp)(void const *, void const *)
);

/**
 * @brief      Create new string using malloc wrapper
 * 
 * details     Malloc errors aren't catched as long as the standards does not
 *             define these kind of behaviors.
 *              ==>> https://linux.die.net/man/3/malloc
 *              ==>> http://linuxfr.org/users/gouttegd/journaux/gestion-des-erreurs-d-allocation-memoire-en-c
 *
 * @param      size  The size (+1)
 *
 * @return     ft_strnew return a valid memory area cleared, or NULL.
 */
char    	*ft_strnew(size_t size);

/**
 * @brief      Erase pointer
 *
 * @param      ptr   The pointer
 */
void    	ft_strdel(char **ptr);

/**
 * @brief       The ft_strlen function computes the length of the string s
 *
 * @param s		String
 * @return      Number of characters that precede the terminating NUL character
 */
size_t  	ft_strlen(char const *s);

/**
 * @brief       The ft_strnlen function attempts to compute the length of s,
 *              but never scans beyond the first maxn bytes of s.
 *
 * @param s		String
 * @param maxn	Max len
 * @return      Either the same result as ft_strlen or maxn,
 *              whichever is smaller.
 */
size_t  	ft_strnlen(char const *s, size_t maxn);

/**
 * @brief      Copy string
 *
 * details     The ft_strcpy() function copy the string src to dst
 * 			   (including the terminating `\0' character.)
 *
 * @param      dst   The destination
 * @param      src   The source
 *
 * @return     The ft_strcpy() function return dst.
 */
char    	*ft_strcpy(char *dst, char const *src);

/**
 * @brief      Copy string
 *
 * details     The ft_strncpy() function copy at most len characters from
 *			   src into dst. If src is less than len characters long, the
 *			   remainder of dst is filled with `\0' characters. Otherwise,
 *			   dst is not terminated.
 *
 * @param      dst   The destination
 * @param      src   The source
 * @param      len   The length
 *
 * @return     The ft_strncpy() function return dst.
 */
char    	*ft_strncpy(char *dst, char const *src, size_t len);

/**
 * @brief      Copy string
 *
 * details     The ft_stpcpy() function copy the string src to dst
 * 			   (including the terminating `\0' character.)
 * 
 * @param      dst   The destination
 * @param      src   The source
 *
 * @return     The ft_stpcpy() function return a pointer to the
 *             terminating `\0' character of dst.
 */
char    	*ft_stpcpy(char *dst, char const *src);

/**
 * @brief      Copy string
 * 
 * details     The ft_stpncpy() function copy at most len characters from
 *			   src into dst. If src is less than len characters long, the
 *			   remainder of dst is filled with `\0' characters. Otherwise,
 *			   dst is not terminated.
 *			   
 * @param      dst   The destination
 * @param      src   The source
 * @param      len   The length
 *
 * @return     The ft_stpncpy() function return a pointer to the terminating
 *             `\0' character of dst. If ft_stpncpy() does not terminate dst
 *             with a NULL character, it instead returns a pointer to dst[n]
 *             (which does not necessarily refer to a valid memory location)
 */
char    	*ft_stpncpy(char *dst, char const *src, size_t len);

/**
 * @brief      Locate character in string
 * 
 * details     The ft_strchr() function locates the first occurrence of c
 * 			   (converted to a char) in the string pointed to by s. The
 *       	   terminating null character is considered to be part of the
 *       	   string; therefore if c is `\0', the functions locate the
 *       	   terminating `\0'.
 *
 * @param      src   The source
 * @param      c     The char to locate (fully promoted type)
 *
 * @return     The function ft_strchr() return a pointer to the located
 *             character, or NULL if the character does not appear in
 *             the string.
 */
char    	*ft_strchr(char const *src, int c);

/**
 * @brief      Locate character in string
 *
 * details     The ft_strrchr() function is identical to strchr(), except
 * 			   it locates the last occurrence of c.
 *
 * @param      src   The source
 * @param      c     The char to locate (fully promoted type)
 *
 * @return     The function ft_strrchr() return a pointer to the located
 *             character, or NULL if the character does not appear in
 *             the string.
 */
char    	*ft_strrchr(char const *src, int c);

/**
 * @brief      Save a copy of a string
 * 
 * details     The ft_strdup() function allocates sufficient memory for
 * 			   a copy of the string src, does the copy, and returns a
 *       	   pointer to it. The pointer may subsequently be used as
 *       	   an argument to the function ft_strdel.
 *
 * @param      src   The source
 *
 * @return     The new string or NULL
 */
char    	*ft_strdup(char const *src);

/**
 * @brief      Save a copy of a string
 * 
 * details     The ft_strndup() function copies at most len characters from
 * 			   the string src always NUL terminating the copied string.
 *
 * @param      src   The source
 * @param      len	 The length
 *
 * @return     The new string or NULL
 */
char    	*ft_strndup(char const *src, size_t len);

/**
 * @brief      Compare string
 * 
 * details     The ft_strequ() function lexicographically compare the
 * 			   null-terminated strings s1 and s2.
 *
 * @param      s1    The first string
 * @param      s2    The second string
 *
 * @return     The ft_strequ() function return 1 if both strings are equals,
 *             otherwise 0.
 */
int     	ft_strequ(char const *s1, char const *s2);

/**
 * @brief      Compare string
 * 
 * details     The ft_strnequ() function lexicographically compare the
 * 			   null-terminated strings s1 and s2, but it does not compare
 * 			   more than n characters.
 *
 * @param      s1    The first string
 * @param      s2    The second string
 * @param 	   len	 The length
 *
 * @return     The ft_strnequ() function return 1 if both strings are equals,
 *             otherwise 0.
 */
int     	ft_strnequ(char const *s1, char const *s2, size_t len);

/**
 * @brief      Find first occurence of `func` in string
 *
 * @param      string  The string
 * @param[in]  func    The function
 *
 * @return     The ft_strfind function return a pointer to the first
 *             occurence of `func` on success, otherwise 0.
 */
char    	*ft_strfind(char const *string, int (*func)(int));

/**
 * @brief      Apply func on string
 *
 * details     The ft_strapply() function apply `func` to every char
 * 			   in nul-terminated string. The function stop whenever it
 * 			   meet the '\0' or when the function applied return a '\0'. 
 *
 * @param      string  The string
 * @param[in]  func    The function
 */
void		ft_strapply(char *string, int (*func)(int));

/**
 * @brief      Compare strings
 *
 * details     The ft_strcmp() function lexicographically compare the
 * 			   null-terminated strings s1 and s2.
 *
 * @param      s1    The first string
 * @param      s2    The second string
 *
 * @return     The ft_strcmp() function return an integer greater than,
 *             equal to, or less than 0, according as the string s1 is
 *             greater than, equal to, or less than the string s2. The
 *             comparison is done using unsigned characters, so that
 *             `\200' is greater than `\0'.
 */
int     	ft_strcmp(char const *s1, char const *s2);

/**
 * @brief      Compare strings
 *
 * details     The ft_strncmp() function lexicographically compare the
 * 			   null-terminated strings s1 and s2. The ft_strncmp()
 *       	   function compares not more than n characters. Because
 *       	   ft_strncmp() is designed for comparing strings rather
 *       	   than binary data, characters that appear after a `\0'
 *       	   character are not compared.
 *
 * @param      s1    The first string
 * @param      s2    The second string
 * @param      len   The length
 *
 * @return     The ft_strncmp() function return an integer greater than,
 *             equal to, or less than 0, according as the string s1 is
 *             greater than, equal to, or less than the string s2. The
 *             comparison is done using unsigned characters, so that
 *             `\200' is greater than `\0'.
 */
int     	ft_strncmp(char const *s1, char const *s2, size_t len);

/**
 * @brief      Concatenate strings
 * 
 * details     The ft_strcat() function append a copy of the null-terminated
 * 			   string src to the end of the null-terminated string dst, then
 * 			   add a terminating `\0'. The string dst must have sufficient
 * 			   space to hold the result. The source and destination strings
 * 			   should not overlap, as the behavior is undefined.
 *
 * @param      dst   The destination
 * @param      src   The source
 *
 * @return     The ft_strcat() function return the pointer dst.
 */
char    	*ft_strcat(char *dst, char const *src);

/**
 * @brief      Concatenate strings
 * 
 * details     The ft_strncat() function append a copy of the null-terminated
 * 			   string src to the end of the null-terminated string dst, then
 * 			   add a terminating `\0'. The string dst must have sufficient
 * 			   space to hold the result. The ft_strncat() function appends not 
 * 			   more than len characters from src, and then adds a terminating
 * 			   `\0'. The source and destination strings should not overlap, as
 * 			   the behavior is undefined.
 *
 * @param      dst   The destination
 * @param      src   The source
 * @param 	   n	 The length
 *
 * @return     The ft_strncat() function return the pointer dst.
 */
char    	*ft_strncat(char *dst, char const *src, size_t n);

/**
 * @brief      Separate strings
 * 
 * details     The ft_strsep() function locates, in the string referenced
 * 			   by *src, the first occurrence of any character in the string
 *       	   delim (or the terminating `\0' character) and replaces it
 *       	   with a `\0'. The location of the next character after the
 *       	   delimiter character (or NULL, if the end of the string was
 *       	   reached) is stored in *src. The original value of *src is
 *       	   returned. An "empty" field (i.e., a character in the string
 *       	   delim occurs as the first character of *src) can be detected
 *       	   by comparing the location referenced by the returned pointer
 *       	   to `\0'. If *src is initially NULL, ft_strsep() returns NULL.
 *
 * @param      src    The source
 * @param      delim  The delimiter
 *
 * @return     The ft_strsep function return a new string from src separated
 *             by delim.
 */
char    	*ft_strsep(char **src, char const *delim);

/**
 * @brief      Locate a substring in a string
 * 
 * details     The ft_strstr() function locates the first occurrence of the
 * 			   null-terminated string needle in the null-terminated string
 * 			   haystack.
 *
 * @param      haystack  The haystack
 * @param      needle    The needle
 *
 * @return     If needle is an empty string, haystack is returned; if needle
 *             occurs nowhere in haystack, NULL is returned; otherwise a
 *             pointer to the first character of the first occurrence of
 *             needle is returned.
 */
char    	*ft_strstr(char const *haystack, char const *needle);

/**
 * @brief      Locate a substring in a string
 *
 * details     The ft_strnstr() function locates the first occurrence of the
 * 			   null-terminated string needle in the string haystack, where not
 *       	   more than len characters are searched.  Characters that appear
 *       	   after a `\0' character are not searched. Since the ft_strnstr()
 *       	   function is a FreeBSD specific API, it should only be used when
 *       	   portability is not a concern.
 *
 * @param      haystack  The haystack
 * @param      needle    The needle
 * @param      len		 The length
 *
 * @return     If needle is an empty string, haystack is returned; if needle
 *             occurs nowhere in haystack, NULL is returned; otherwise a
 *             pointer to the first character of the first occurrence of
 *             needle is returned.
 */
char    	*ft_strnstr(char const *haystack, char const *needle, size_t len);

/**
 * @brief      Span a string
 *
 * details     The ft_strspn() function spans the initial part of the
 * 			   null-terminated string src as long as the characters
 *     		   from src occur in the null-terminated string accept.
 *     		   In other words, it computes the string array index of
 *     		   the first character of src which is not in accept,
 *     		   else the index of the first null character.
 *
 * @param      src     The source
 * @param      accept  The accept
 *
 * @return     The ft_strspn() function return the number of characters
 *             spanned.
 */
size_t  	ft_strspn(char const *src, char const *accept);

/**
 * @brief      Span a string
 * 
 * details     The ft_strcspn() function spans the initial part of the
 * 			   null-terminated string src as long as the characters
 *       	   from src do not occur in the null-terminated string
 *       	   reject (it spans the complement of reject). In other
 *       	   words, it computes the string array index of the first
 *       	   character of src which is also in reject, else the index
 *       	   of the first null character.
 *
 * @param      src     The source
 * @param      reject  The reject
 *
 * @return     The ft_strcspn() function return the number of characters
 *             spanned.
 */
size_t  	ft_strcspn(char const *src, char const *reject);

/**
 * @brief      Join strings
 * 
 * details     The ft_strjoin function joins 2 strings into a new one.
 *
 * @param      s1    The first string
 * @param      s2    The second string
 *
 * @return     The ft_strjoin function return a new string that is
 *             the concatenation of 2 strings.
 */
char    	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief      Split string
 *
 * details     The ft_strsplit function split the string src using
 * 			   a function ptr to check char by char which one is a
 * 			   delimiter.
 *
 * @param      src   The source
 * @param      func  The function used (ctype.h prototype)
 *
 * @return     The ft_strsplit function return a new tab with all result.
 */
char    	**ft_strsplit(char const *src, int (*func)(int));

/**
 * @brief      New string struct that contain size and capacity
 */
typedef struct			s_string
{
	size_t				capacity;
	size_t				len;
	char				*str;
}						t_string;

/**
 * @brief Min capacity for string by default: 8
 */
# define FT_STRING_CAPACITY_DFT		(0x8)

/**
 * @brief      Alocate new string with capacity^n > size
 *
 * @param[in]  size  The size
 *
 * @return     new alocated string
 */
t_string	*ft_string_new(size_t size);

/**
 * @brief      Erase string, using ft_memdel()/ft_strdel()
 *
 * @param      string_ptr  The string pointer
 */
void		ft_string_del(t_string **string_ptr);

/**
 * @brief      Clear string
 *
 * @param      string  The string to clear
 */
void		ft_string_clear(t_string *string);

/**
 * @brief      Save a copy of a string
 *
 * details     The ft_string_dup() function allocates sufficient memory
 * 			   for a copy of the string src, does the copy, and returns
 * 			   a pointer to string. The  pointer  may  subsequently be
 * 			   used as an argument to the function ft_string_del().
 *       	   
 * @param      str   The string
 *
 * @return     The new string
 */
t_string	*ft_string_dup(char const *str);

/**
 * @brief      Save a copy of a string
 * 
 * details     The ft_string_ndup() function copies at most len
 * 			   characters  from  the  string  str  always  NUL
 * 			   terminating the copied string.
 *
 * @param      str   The string
 * @param      nb	 The length
 *
 * @return     The new string or NULL
 */
t_string	*ft_string_ndup(char const *str, size_t nb);

/**
 * @brief      Copy string
 *
 * details     The ft_string_cpy() function copy the string
 * 			   str  to  the  string (including the
 * 			   terminating `\0' character.)
 *
 * @param      string	The string
 * @param      str   	The string
 *
 * @return     The ft_string_cpy() function return string.
 */
t_string	*ft_string_cpy(t_string *string, char const *str);

/**
 * @brief      Copy string
 *
 * details     The ft_string_ncpy() function copy at most len
 * 			   characters from str into string.If str is less
 * 			   than len  characters  long, the  remainder  of
 * 			   string is filled with `\0' characters. Otherwise,
 * 			   string is not terminated.
 *
 * @param      string   The string
 * @param      str   	The string
 * @param      nb   	The length
 *
 * @return     The ft_string_ncpy() function return string.
 */
t_string	*ft_string_ncpy(t_string *string, char const *str, size_t nb);

/**
 * @brief      Concatenate strings
 * 
 * details     The ft_string_cat() function append a copy of the
 * 			   null-terminated str, string src to the end of the
 * 			   null-terminated string add  a  terminating `\0'.
 *
 * @param      string   The string
 * @param      str   	The string
 *
 * @return     The ft_strcat() function return the pointer dst.
 */
t_string	*ft_string_cat(t_string *string, char const *str);

/**
 * @brief      Concatenate strings
 * 
 * details     The ft_string_ncat() function append a copy of the
 * 			   null-terminated string str to the end of the null-
 * 			   terminated string, then add  a  terminating `\0'.
 * 			   The ft_string_ncat  function appends not more than
 * 			   len characters from str, and then adds a terminating
 * 			   `\0'.
 *
 * @param      string   The destination
 * @param      str   	The source
 * @param 	   len	 	The length
 *
 * @return     The ft_string_ncat() function return the string.
 */
t_string	*ft_string_ncat(t_string *string, char const *str, size_t len);

/**
 * @brief      Append strings
 * 
 * details     The ft_string_add() function add a char to the
 * 			   string. It does not add '\0'.
 *
 * @param      string   The destination
 * @param      c   		The character to add
 *
 * @return     The ft_string_add() function return the string.
 */
t_string	*ft_string_add(t_string *string, int c);

/**
 * @brief      Append strings
 * 
 * details     The ft_string_nadd() function add chars to the
 * 			   string but not more than nb times. It also
 * 			   does not add '\0'.
 *
 * @param      string   The destination
 * @param      c   		The character to add
 * @param 	   nb		The number of chars to append
 *
 * @return     The ft_string_nadd() function return the string.
 */
t_string	*ft_string_nadd(t_string *string, int c, size_t nb);

/**
 * @brief      Insert string
 * 
 * details     The ft_string_insert() function insert str
 * 			   at `pos' in the string.
 *
 * @param      string   The string destination
 * @param      str   	The string to insert
 * @param 	   pos		The position to insert
 *
 * @return     The ft_string_insert() function return the string.
 */
t_string	*ft_string_insert(t_string *string, char const *str, size_t pos);

/**
 * @brief      Remove len bytes in string
 * 
 * details     The ft_string_remove() function remove nb bytes
 * 			   in string starting at pos.
 *
 * @param      string   The string destination
 * @param      pos   	The position
 * @param 	   nb		The number of bytes
 *
 * @return     The ft_string_remove() function return the string.
 */
t_string	*ft_string_remove(t_string *string, size_t pos, size_t nb);

/**
 * @brief      Delete string in string
 * 
 * details     The ft_string_textract() function remove to_find
 * 			   str if it exists in string.
 *
 * @param      string   The string destination
 * @param      to_find 	The string to find
 *
 * @return     The ft_string_extract() function return the string.
 */
t_string	*ft_string_extract(t_string *string, char const *to_find);
/**
 * @brief      Replace string
 * 
 * details     The ft_string_replace() function find `find` in
 * 			   string and replace it by `rep`.
 *
 * @param      s   The string destination
 * @param      find   	The string to find
 * @param 	   rep		The string to insert
 *
 * @return     The ft_string_replace() function return the string.
 */
t_string    *ft_string_replace(t_string *s, char const *find, char const *rep);

/**
 * @brief      Resize string if needed
 *
 * details     You shouldn't have to use it.
 * 
 * @param      string    The string to resize
 * @param[in]  new_size  The size to update
 *
 * @return     0 on success, otherwise not 0
 */
int			ft_string_resize(t_string *string, size_t new_size);

/**
 * @brief      Extract the base portion of a pathname
 *
 * @details    The ft_str_basename() function returns the last
 *             component from the pathname pointed to by path,
 *             deleting any trailing `/' characters.  If  path
 *             consists entirely of `/' characters, a  pointer
 *             to the string "/" is returned. If path is a null
 *             pointer  or the  empty string, a pointer to the
 *             string "." is returned.
 *
 * @param      path  The path
 *
 * @return     On successful completion, ft_str_basename return
 *             a pointer to  the last  component of path. If it
 *             fails, a null pointer is returned.
 */
char		*ft_str_basename(char const *path);

/**
 * @brief      Extract the directory part of a pathname
 *
 * @details    The ft_str_dirname() function is the converse of
 *             ft_str_basename(); it  returns a pointer  to the
 *             parent directory  of the pathname  pointed to by
 *             path. Any trailing `/' characters are nt counted
 *             as part of the directory name. If path is a null
 *             pointer, the  empty  string, or  contains no `/'
 *             characters,  ft_str_dirname() returns a  pointer
 *             to the string ".".
 *              
 * @param      path  The path
 *
 * @return     The ft_str_dirname() function returns a pointer
 *             to internal storage space allocated on the first
 *             call that will be overwritten by subsequent calls.
 */
char		*ft_str_dirname(char const *path);

#endif
