/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:26:51 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:39:59 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
		*p++ = 0;
}
/*
#include <stdio.h>
int	main()
{
	char str[] = "abc";

	printf("%s\n", str);
	ft_bzero(str, 3);
	printf("%s\n", str);
	for (int i = 0; i < 3; i++)
		printf("str[%d] = %d\n", i, str[i]);
}
*/
