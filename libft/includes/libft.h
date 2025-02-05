/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:31:43 by cauvray           #+#    #+#             */
/*   Updated: 2024/12/12 02:48:52 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Checks if the character is alphanumeric.
 *
 * This function checks if the character c is either a letter (a-z, A-Z)
 * or a digit (0-9).
 *
 * @param c The character to be checked, passed as an int
 * (typically cast from a char).
 * @return Non-zero if the character is alphanumeric, zero otherwise.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks if the character is an alphabetic letter.
 *
 * This function checks if the character c is a letter (a-z, A-Z).
 *
 * @param c The character to be checked, passed as an int
 * (typically cast from a char).
 * @return Non-zero if the character is alphabetic, zero otherwise.
 */
int		ft_isalpha(int c);

/**
 * @brief Checks if the character is an ASCII character.
 *
 * This function checks if the character c is in the ASCII range (0-127).
 *
 * @param c The character to be checked, passed as an int
 * (typically cast from a char).
 * @return Non-zero if the character is an ASCII character, zero otherwise.
 */
int		ft_isascii(int c);

/**
 * @brief Checks if the character is a digit.
 *
 * This function checks if the character c is a digit (0-9).
 *
 * @param c The character to be checked, passed as an int
 * (typically cast from a char).
 * @return Non-zero if the character is a digit, zero otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks if the character is a lowercase letter.
 *
 * This function checks if the character c is a lowercase letter (a-z).
 *
 * @param c The character to be checked, passed as an int
 * (typically cast from a char).
 * @return Non-zero if the character is lowercase, zero otherwise.
 */
int		ft_islower(int c);

/**
 * @brief Checks if the character is a printable character.
 *
 * This function checks if the character c is a printable character,
 * which includes letters, digits, punctuation, and space.
 *
 * @param c The character to be checked, passed as an int
 * (typically cast from a char).
 * @return Non-zero if the character is printable, zero otherwise.
 */
int		ft_isprint(int c);

/**
 * @brief Checks if the character is a whitespace character.
 *
 * This function checks if the character c is a whitespace character,
 * which includes space, tab, newline, vertical tab, form feed,
 * and carriage return.
 *
 * @param c The character to be checked, passed as an int
 * (typically cast from a char).
 * @return Non-zero if the character is a whitespace character, zero otherwise.
 */
int		ft_isspace(int c);

/**
 * @brief Checks if the character is an uppercase letter.
 *
 * This function checks if the character c is an uppercase letter (A-Z).
 *
 * @param c The character to be checked, passed as an int
 * (typically cast from a char).
 * @return Non-zero if the character is uppercase, zero otherwise.
 */
int		ft_isupper(int c);

/**
 * @brief Adds a new element at the end of the list.
 *
 * This function adds the element pointed to by new at
 * the end of the list pointed to by lst.
 *
 * @param lst A pointer to the pointer of the first element of the list.
 * @param new A pointer to the new element to be added.
 *
 * @note If the list is empty, the new element becomes the first element.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Adds a new element at the beginning of the list.
 *
 * This function adds the element pointed to by new at
 * the beginning of the list pointed to by lst.
 *
 * @param lst A pointer to the pointer of the first element of the list.
 * @param new A pointer to the new element to be added.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Clears and frees the list.
 *
 * This function frees all the elements of the list pointed to
 * by lst and sets the pointer to NULL.
 * The function del is used to free the content of each element.
 *
 * @param lst A pointer to the pointer of the first element of the list.
 * @param del A pointer to a function that frees the content of an element.
 *
 * @note After this function is called, the list will be empty
 * and lst will be set to NULL.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Deletes a single element from the list.
 *
 * This function deletes the element pointed to by lst
 * and frees its content using the del function.
 *
 * @param lst A pointer to the element to be deleted.
 * @param del A pointer to a function that frees the content of the element.
 *
 * @note After this function is called, the pointer lst should not be used.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Returns the element of the list at the given index.
 *
 * This function returns a pointer to the element
 * of the list at the given index.
 *
 * @param lst A pointer to the first element of the list.
 * @param index A index of the element in the list
 * @return A pointer to the element of the list at the given index,
 * NULL if the list is empty or last element if index is superior to list size.
 */
t_list	*ft_lstget(t_list *lst, int index);

/**
 * @brief Iterates over the list and applies a function to each element
 * with the ptr as second parameter.
 *
 * This function applies the function f to the content of
 * each element in the list pointed to by lst with the ptr as second parameter.
 *
 * @param lst A pointer to the first element of the list.
 * @param f A pointer to a function that takes a pointer
 * to the content of an element and a ptr, given in function as third parameter.
 * @param ptr The third parameter and second arg of the function
 */
void	ft_lstiter_param(t_list *lst, void (*f)(void *, void *), void *ptr);

/**
 * @brief Iterates over the list and applies a function to each element.
 *
 * This function applies the function f to the content of
 * each element in the list pointed to by lst.
 *
 * @param lst A pointer to the first element of the list.
 * @param f A pointer to a function that takes a pointer
 * to the content of an element.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Returns the last element of the list.
 *
 * This function returns a pointer to the last element
 * of the list pointed to by lst.
 *
 * @param lst A pointer to the first element of the list.
 * @return A pointer to the last element of the list,
 * or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Creates a new list by applying a function
 * to each element of the original list.
 *
 * This function applies the function f to each element
 * of the list lst and creates a new list
 * with the results. The function del is used to free the content
 * of the new elements if needed.
 *
 * @param lst A pointer to the first element of the original list.
 * @param f A pointer to a function that takes a pointer to an element
 * and returns a pointer to the new content.
 * @param del A pointer to a function that frees the content
 * of an element if necessary.
 * @return A pointer to the new list, or NULL if the allocation fails.
 *
 * @note If the original list is NULL, the function should return NULL.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Creates a new element of the list.
 *
 * This function allocates memory for a new list element and sets
 * its content to the value pointed to by content.
 *
 * @param content A pointer to the content to be set in the new element.
 * @return A pointer to the new list element, or NULL if the allocation fails.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Counts the number of elements in the list.
 *
 * This function returns the number of elements in the list pointed to by lst.
 *
 * @param lst A pointer to the first element of the list.
 * @return The number of elements in the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Sets the first n bytes of the block of memory pointed to by s to zero.
 *
 * This function writes n zeroed bytes to the memory area pointed to by s.
 * It is commonly used to initialize memory blocks.
 *
 * @param s A pointer to the memory area to be filled with zeros.
 * It must be a valid pointer, and the memory area should be large
 * enough to hold n bytes.
 * @param n The number of bytes to be set to zero. If n is zero, the function
 * does nothing.
 *
 * @note This function does not return a value.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Allocates memory for an array and initializes it to zero.
 *
 * This function allocates memory for an array of `nmemb` elements, each of
 * size `size`, and initializes all bytes in the allocated memory to zero.
 * It is equivalent to allocating memory with `malloc` and then using `memset`
 * to set all bytes to zero.
 *
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element in bytes.
 * @return A pointer to the allocated memory.
 * If the allocation fails, NULL is returned.
 *
 * @note If `nmemb` or `size` is zero, the function returns NULL.
 * @note The memory allocated must be freed by the caller using `free`
 * when no longer needed.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Locates the first occurrence of a character in memory.
 *
 * This function scans the first n bytes of the memory area
 * pointed to by s for the first occurrence
 * of the character c. The function returns a pointer
 * to the located character, or NULL if the character is not found
 * within the specified range.
 *
 * @param s A pointer to the memory area to be scanned.
 * @param c The character to search for (passed as an int).
 * @param n The number of bytes to scan.
 * @return A pointer to the first occurrence of c in the memory area,
 * or NULL if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares two memory areas.
 *
 * This function compares the first n bytes of the memory areas
 * pointed to by s1 and s2.
 * The comparison is done byte by byte, and the function returns:
 * - A negative integer if s1 is less than s2,
 * - Zero if they are equal,
 * - A positive integer if s1 is greater than s2.
 *
 * @param s1 A pointer to the first memory area.
 * @param s2 A pointer to the second memory area.
 * @param n The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero
 * if the first n bytes of s1
 * is found to be less than, to match, or be greater than s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copies memory area.
 *
 * This function copies n bytes from the memory area pointed to
 * by src to the memory area pointed to by dest.
 * The two memory areas must not overlap; use ft_memmove if they do overlap.
 *
 * @param dest A pointer to the destination memory area
 * where the content is to be copied.
 * @param src A pointer to the source memory area from
 * which the content is to be copied.
 * @param n The number of bytes to copy.
 * @return A pointer to the destination memory area dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Moves memory area.
 *
 * This function copies n bytes from the memory area pointed to
 * by src to the memory area pointed to by dest.
 * Unlike ft_memcpy, this function is safe to use when
 * the memory areas overlap; it will handle the copy correctly.
 *
 * @param dest A pointer to the destination memory area
 * where the content is to be copied.
 * @param src A pointer to the source memory area from
 * which the content is to be copied.
 * @param n The number of bytes to move.
 * @return A pointer to the destination memory area dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Sets a memory area to a specific value.
 *
 * This function fills the first n bytes of the memory area pointed to
 * by s with the constant byte c.
 *
 * @param s A pointer to the memory area to be filled.
 * @param c The value to set (passed as an int,
 * but converted to unsigned char).
 * @param n The number of bytes to set to the value c.
 * @return A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Writes a character to the specified file descriptor.
 *
 * This function writes the character c to the file descriptor specified by fd.
 *
 * @param c The character to be written.
 * @param fd The file descriptor where the character will be written.
 *
 * @note If fd is invalid, the behavior of the function is undefined.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Writes a string to the specified file descriptor.
 *
 * This function writes the string s to the file descriptor fd with newline.
 *
 * @param s The string to be written without new line.
 * @param fd The file descriptor where the string will be written.
 *
 * @note If s is NULL, the function does nothing. If fd is invalid,
 * the behavior of the function is undefined.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Writes an integer to the specified file descriptor.
 *
 * This function writes the integer n to the file descriptor fd as a string.
 *
 * @param n The integer to be written.
 * @param fd The file descriptor where the integer will be written.
 *
 * @note If fd is invalid, the behavior of the function is undefined.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Writes a string to the specified file descriptor.
 *
 * This function writes the string s to the file descriptor fd.
 *
 * @param s The string to be written.
 * @param fd The file descriptor where the string will be written.
 *
 * @note If s is NULL, the function does nothing. If fd is invalid,
 * the behavior of the function is undefined.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Calculates the length of an integer when represented as a string.
 *
 * This function computes the number of digits in the integer n.
 *
 * @param n The integer whose length is to be calculated.
 * @return The number of digits in the integer n.
 *
 * @note This function handles negative numbers
 * by counting the '-' sign as well.
 */
size_t	ft_nbrlen(int n);

/**
 * @brief Splits a string into an array of strings based on a delimiter.
 *
 * This function takes a string s and splits it into substrings
 * using the character c as a delimiter.
 * The resulting substrings are stored in an array,
 * which is terminated by a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return An array of strings (substrings), or NULL if allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated
 * for the array and its contents.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * This function returns a pointer to the first occurrence of
 * the character c in the string s.
 * If the character is not found, it returns NULL.
 *
 * @param s The string to be searched.
 * @param c The character to locate (passed as an int).
 * @return A pointer to the first occurrence of c in s, or NULL if not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Join the two strings
 *
 * This function returns a pointer to the malloc string
 * The s1 parameter is free.
 *
 * @param s1 The first string to join (which is free).
 * @param s2 The second string to join (which isn't free).
 * @return The joined string
 */
char	*ft_strcleanjoin(char *s1, char *s2);

/**
 * @brief Duplicates a string.
 *
 * This function allocates sufficient memory for a copy of the string s,
 * copies it into the newly allocated memory,
 * and returns a pointer to the duplicated string.
 *
 * @param s The string to be duplicated.
 * @return A pointer to the duplicated string, or NULL if allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated
 * for the duplicated string.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Applies a function to each character of a string with its index.
 *
 * This function iterates over the string s and applies
 * the function f to each character.
 * The index of the character is also passed to the function f.
 *
 * @param s The string to iterate over.
 * @param f A pointer to a function that takes an unsigned int
 * and a char pointer.
 *
 * @note If s is NULL, the function does nothing.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Concatenates two strings into a new string.
 *
 * This function allocates memory for a new string that is
 * the result of concatenating s1 and s2.
 * The new string is terminated by a NULL character.
 *
 * @param s1 The first string to concatenate.
 * @param s2 The second string to concatenate.
 * @return A pointer to the newly allocated string containing s1
 * followed by s2,
 * or NULL if allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated
 * for the concatenated string.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Appends a string to the end of another string with size limit.
 *
 * This function appends the string src to the end of dst, up to size bytes,
 * and guarantees null-termination of the resulting string.
 * The size parameter specifies the total size of the destination buffer.
 *
 * @param dst The destination string to which src will be appended.
 * @param src The source string to append.
 * @param size The size of the destination buffer.
 * @return The total length of the string that would have been created
 * if there was enough space,
 * which is the length of dst plus the length of src.
 *
 * @note If size is less than the length of dst,
 * the return value will be the length of dst plus the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Copies a string to a destination with size limit.
 *
 * This function copies the string src to dst,
 * ensuring that dst is null-terminated
 * if size is greater than 0.
 * The size parameter specifies the total size of the destination buffer.
 *
 * @param dst The destination buffer where the string will be copied.
 * @param src The source string to copy.
 * @param size The size of the destination buffer.
 * @return The length of the source string.
 *
 * @note If size is 0, the destination buffer is not modified.
 * If size is less than the length of src, dst will not be null-terminated.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Calculates the length of a string.
 *
 * This function computes the length of the string s,
 * excluding the terminating null byte.
 *
 * @param s The string whose length is to be calculated.
 * @return The length of the string s.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Applies a function to each character of a string,
 * creating a new string.
 *
 * This function iterates over the string s and applies
 * the function f to each character,
 * producing a new string where each character is the result of the function.
 *
 * @param s The string to iterate over.
 * @param f A pointer to a function that takes an unsigned int (index)
 * and a char, and returns a char.
 * @return A pointer to the newly created string, or NULL if allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated
 * for the new string.
 * If s is NULL, the function does nothing and returns NULL.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Compares two strings up to a specified number of characters.
 *
 * This function compares the first n characters of the strings s1 and s2.
 * The comparison is done lexicographically and returns:
 * - A negative integer if s1 is less than s2,
 * - Zero if they are equal,
 * - A positive integer if s1 is greater than s2.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero
 * if the first n characters of s1
 * is found to be less than, to match, or be greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Duplicates a substring of a given string.
 *
 * This function allocates memory and creates a new string
 * that contains the first n characters of str.
 * If n is greater than the length of str, the entire string is duplicated.
 *
 * @param str The string to duplicate.
 * @param n The maximum number of characters to copy from str.
 * @return A pointer to the newly allocated string,
 * or NULL if allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated
 * for the duplicated string.
 */
char	*ft_strndup(char const *str, int n);

/**
 * @brief Locates a substring within a specified length of a string.
 *
 * This function finds the first occurrence
 * of the substring little in the string big, searching only within
 * the first len characters of big.
 * If little is an empty string, big is returned.
 *
 * @param big The string to search in.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search in big.
 * @return A pointer to the first occurrence of little in big,
 * or NULL if not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Locates the last occurrence of a character in a string.
 *
 * This function returns a pointer to the last occurrence
 * of the character c in the string s.
 * If the character is not found, it returns NULL.
 *
 * @param s The string to be searched.
 * @param c The character to locate (passed as an int).
 * @return A pointer to the last occurrence of c in s, or NULL if not found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Reverses a string in place.
 *
 * This function reverses the characters of the string str.
 * The string is modified directly, and no new memory is allocated.
 *
 * @param str The string to be reversed.
 * @return A pointer to the reversed string.
 *
 * @note If str is NULL, the behavior is undefined.
 */
char	*ft_strrev(char *str);

/**
 * @brief Trims specified characters from the start and end of a string.
 *
 * This function allocates memory for a new string
 * that contains a copy of the string s1
 * with all occurrences of the characters specified in set removed
 * from the beginning and end.
 *
 * @param s1 The string to trim.
 * @param set The set of characters to remove.
 * @return A pointer to the newly allocated trimmed string,
 * or NULL if allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated
 * for the trimmed string.
 * If s1 or set is NULL, the function does nothing and returns NULL.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Extracts a substring from a string.
 *
 * This function allocates memory for a new string
 * that contains a substring of s,
 * starting from index start and with a maximum length of len.
 * If start is greater than the length of s, the result is an empty string.
 *
 * @param s The string from which to extract the substring.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return A pointer to the newly allocated substring,
 * or NULL if allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated
 * for the substring.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Converts a string to an integer.
 *
 * This function converts the initial portion of the string pointed to by
 * nptr to its integer representation. Leading whitespace characters are
 * ignored. If the string contains invalid characters, the conversion stops
 * at the first non-numeric character.
 *
 * @param s A pointer to the string to be converted. The string must be
 *   null-terminated.
 * @return The converted integer value. If the converted value is outside
 * the range of representable values, behavior is undefined.
 *
 * @note The function does not handle overflow. Ensure that the input string
 * represents a valid integer within the range of the return type.
 */
int		ft_atoi(const char *s);

/**
 * @brief Converts a string to an long integer.
 *
 * This function converts the initial portion of the string pointed to by
 * nptr to its long integer representation. Leading whitespace characters are
 * ignored. If the string contains invalid characters, the conversion stops
 * at the first non-numeric character.
 *
 * @param s A pointer to the string to be converted. The string must be
 *   null-terminated.
 * @return The converted long integer value. If the converted value is outside
 * the range of representable values, behavior is undefined.
 *
 * @note The function does not handle overflow. Ensure that the input string
 * represents a valid long integer within the range of the return type.
 */
long	ft_atol(const char *s);

/**
 * @brief Converts an integer to a string.
 *
 * This function converts the integer n to a string
 * (a null-terminated character array).
 * It handles negative numbers by adding a '-' sign to the beginning
 * of the string.
 *
 * @param n The integer to convert.
 * @return A pointer to the newly allocated string representing the integer,
 * or NULL if allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated
 * for the string.
 */
char	*ft_itoa(int n);

/**
 * @brief Converts an uppercase letter to lowercase.
 *
 * This function takes a character c and, if it is an uppercase letter,
 * converts it to its corresponding lowercase letter.
 * If c is not an uppercase letter, it is returned unchanged.
 *
 * @param c The character to convert.
 * @return The lowercase equivalent of c if c is an uppercase letter;
 * otherwise, c is returned unchanged.
 */
int		ft_tolower(int c);

/**
 * @brief Converts a lowercase letter to uppercase.
 *
 * This function takes a character c and, if it is a lowercase letter,
 * converts it to its corresponding uppercase letter.
 * If c is not a lowercase letter, it is returned unchanged.
 *
 * @param c The character to convert.
 * @return The uppercase equivalent of c if c is a lowercase letter;
 * otherwise, c is returned unchanged.
 */
int		ft_toupper(int c);

#endif