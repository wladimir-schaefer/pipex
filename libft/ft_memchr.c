/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:51:20 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:41:10 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	const char *str = "Hello, World!";
	int a = 'W';
	int b = '1';
	char *result;

	result = (char *)ft_memchr(str, a, 10);
	if (result)
		printf("%s\n", result);
	else
		printf("Not found\n");
	
	result = (char *)ft_memchr(str, b, 10);
	if (result)
		printf("%s\n", result);
	else
		printf("Not found\n");
}
*/
