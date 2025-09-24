/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:24:17 by wschafer          #+#    #+#             */
/*   Updated: 2025/06/06 14:24:19 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_lenth(long int n);
static	char		*convert_int(char *str, long n, size_t len, size_t sign);

int	print_nbr(int i)
{
	char	*str;
	size_t	sign;
	size_t	len;
	long	num;
	int		printed;

	sign = 0;
	num = i;
	if (i < 0)
	{
		sign = 1;
		num = -num;
	}
	len = get_lenth(num);
	str = malloc((len + sign + 1) * sizeof(char));
	if (!str)
		return (-1);
	convert_int(str, num, len, sign);
	printed = print_str(str);
	free(str);
	return (printed);
}

static	size_t	get_lenth(long int n)
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

static	char	*convert_int(char *str, long n, size_t len, size_t sign)
{
	str[len + sign] = '\0';
	while (len-- > 0)
	{
		str[len + sign] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
