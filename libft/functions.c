/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:23:46 by wschafer          #+#    #+#             */
/*   Updated: 2025/06/06 14:24:00 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(int i)
{
	char	c;

	c = (char)i;
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	print_str(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		if (write(1, s, 1) != 1)
			return (-1);
		s++;
		len++;
	}
	return (len);
}

int	print_pointer(void *p)
{
	int				len;
	int				i;
	char			*base;
	char			buffer[16];
	unsigned long	ptr;

	base = "0123456789abcdef";
	if (!p)
		return (write(1, "(nil)", 5));
	ptr = (unsigned long)p;
	if (write(1, "0x", 2) != 2)
		return (-1);
	len = 0;
	while (ptr)
	{
		buffer[len++] = base[ptr % 16];
		ptr /= 16;
	}
	i = len - 1;
	while (i >= 0)
	{
		if (write(1, &buffer[i--], 1) != 1)
			return (-1);
	}
	return (len + 2);
}

int	print_hex(unsigned int u, int uppercase)
{
	int		i;
	int		len;
	char	*base;
	char	buffer[8];

	if (u == 0)
		return (write(1, "0", 1));
	if (uppercase == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	while (u)
	{
		buffer[i++] = base[u % 16];
		u /= 16;
	}
	len = i;
	while (i--)
	{
		if (write(1, &buffer[i], 1) != 1)
			return (-1);
	}
	return (len);
}
