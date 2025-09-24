/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:29:14 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:41:37 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (dest == src || n == 0)
		return (dest);
	s = src;
	d = dest;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
/*
#include <stdio.h>
 int	main(void)
 {
	char src[] = "abc";
	char dst[] = "xyz";

	printf("%s\n", dst);
	ft_memcpy(dst, src, sizeof(src));
	printf("%s\n", dst);
 }
*/