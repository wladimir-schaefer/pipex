/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:30:35 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:42:27 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	if (dsize > 0)
	{
		while (src[i] != '\0' && i < dsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
#include <stdio.h>
int main(void)
{
	char src[] = "Hello, World!";
	char dst[20];
	
	size_t len1 = ft_strlcpy(dst, src, sizeof(dst));
	printf("dst: '%s', len: %zu\n", dst, len1);

	size_t len2 = ft_strlcpy(dst, src, 5);
	printf("dst: '%s', len: %zu\n", dst, len2);	

	return 0;
}
*/
