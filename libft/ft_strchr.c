/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:30:07 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:42:09 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	const char *str = "Hello, World!";
	int a = 87; // 'W'
	printf("%s\n", ft_strchr(str, a));
	int b = 0; // '\0'
	printf("%s\n", ft_strchr(str, b));
}
*/
