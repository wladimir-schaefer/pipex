/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:32:21 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:43:44 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%c\n", ft_toupper('a')); // prints 'A'
	printf("%c\n", ft_toupper('Z')); // prints 'Z'
	printf("%c\n", ft_toupper('1')); // prints '1'
}
*/
