/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:24:25 by wschafer          #+#    #+#             */
/*   Updated: 2025/06/06 14:24:29 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_lenth_unsigned(unsigned int n);
static	char		*convert_unsigned(char *str, unsigned n, size_t len);

int	print_unsigned(unsigned int u)
{
	char	*str;
	size_t	len;
	int		printed;

	len = get_lenth_unsigned(u);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (-1);
	convert_unsigned(str, u, len);
	printed = print_str(str);
	free(str);
	return (printed);
}

static	size_t	get_lenth_unsigned(unsigned int n)
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

static	char	*convert_unsigned(char *str, unsigned n, size_t len)
{
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
