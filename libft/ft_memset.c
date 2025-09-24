/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:29:46 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:42:02 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}
/*
#include <stdio.h>
int	main()
{
	char str[] = "abc";

	printf("%s\n", str);
	ft_memset(str, 'X', 2);
	printf("%s\n", str);
}
*/