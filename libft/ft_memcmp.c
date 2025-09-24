/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:07:38 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:41:19 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*mem1;
	const unsigned char	*mem2;
	size_t				i;

	mem1 = (const unsigned char *) s1;
	mem2 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (mem1[i] != mem2[i])
			return (mem1[i] - mem2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	const char *str1 = "119";
	const char *str2 = "111111";
	printf("%d\n", memcmp(str1, str2, 3));
}
*/
