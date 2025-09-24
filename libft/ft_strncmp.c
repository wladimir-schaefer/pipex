/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:31:10 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:42:44 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 == '\0' || c2 == '\0' || c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	const char *str1 = "abc";
	const char *str2 = "111111";
	printf("%d\n", ft_strncmp(str1, str2, 3));
}
*/
