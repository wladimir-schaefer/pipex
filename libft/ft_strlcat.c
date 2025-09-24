/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:30:22 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:42:18 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	while (dest_len < dsize && dest[dest_len] != '\0')
		dest_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dsize <= dest_len)
		return (dsize + src_len);
	i = 0;
	while ((dest_len + i) < (dsize - 1) && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char buffer[15] = "abc";
	size_t result = ft_strlcat(buffer, "def", 15);
	printf("Result: %zu, Buffer: '%s'\n", result, buffer);
	
	return 0;
}
// Returns the total length of the resulting string after concatenation. 
// If the buffer size is insufficient to accommodate the entire result, 
// it returns the required buffer size.
*/
