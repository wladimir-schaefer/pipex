/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:29:28 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:41:52 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == src || n == 0)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{

	char src[] = "abcdef";
//	char dst[5];

	printf("%s\n", src);
	ft_memmove(src + 2, src, 4);
	printf("%s\n", src);

// Shouldn't crash:
ft_memmove(NULL, NULL, 0); // Safe due to your NULL check

}
*/
