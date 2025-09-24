/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:32:02 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:43:34 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%c\n", ft_tolower('A')); // prints 'a'
	printf("%c\n", ft_tolower('z')); // prints 'z'
	printf("%c\n", ft_tolower('1')); // prints '1'
}
*/
