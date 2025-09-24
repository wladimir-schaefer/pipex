/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:51:12 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:37:38 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>
int main(void)
{
	const char *src = "Hello, World!";
	char *dst;

	printf("src: '%s'\n", src);
	dst = ft_strdup(src);
	if (!dst)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("dst: '%s'\n", dst);
	free(dst);
	return 0;
}
*/