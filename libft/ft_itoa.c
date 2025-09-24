/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:08:52 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/20 16:08:57 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	get_lenth(long n);
static	char		*convert(char *str, long n, size_t i, size_t sign);

char	*ft_itoa(int n)
{
	char	*str;
	size_t	sign;
	size_t	len;
	size_t	i;
	long	num;

	sign = 0;
	num = n;
	if (n < 0)
	{
		sign = 1;
		num = -num;
	}
	len = get_lenth(num);
	str = malloc((len + sign + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = len + sign;
	return (convert(str, num, i, sign));
}

static	size_t	get_lenth(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	char	*convert(char *str, long n, size_t i, size_t sign)
{
	str[i] = '\0';
	while (i-- > sign)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int a = -1234;
	int b = -2147483648;
	char *str;
	char *tmp;

	str = ft_itoa(a);
	tmp = str;
	printf("%s\n", str);
	while (*str)
	{
		printf("%c\n", *str);
		str++;
	}
	free(tmp);

	str = ft_itoa(b);
	printf("%s\n", str);
	free(str);
}
*/