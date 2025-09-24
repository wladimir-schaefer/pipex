/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:48:17 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/29 11:48:22 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	helper(char specifier, va_list args);

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		result;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			result = helper(*s, args);
			if (result == -1)
				return (-1);
			count += result;
		}
		else
			count += print_char(*s);
		s++;
	}
	va_end(args);
	return (count);
}

static	int	helper(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(va_arg(args, int)));
	if (specifier == 's')
		return (print_str(va_arg(args, char *)));
	if (specifier == 'p')
		return (print_pointer(va_arg(args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (print_nbr(va_arg(args, int)));
	if (specifier == 'u')
		return (print_unsigned(va_arg(args, unsigned)));
	if (specifier == 'x')
		return (print_hex(va_arg(args, unsigned), 0));
	if (specifier == 'X')
		return (print_hex(va_arg(args, unsigned), 1));
	if (specifier == '%')
		return (print_char('%'));
	return (-1);
}
/*
#include <stdio.h>
int	main()
{
//	char c = 'C';
//	char *str = "abcdef";
//	int i = -123;
	unsigned u = 305441741; //prints: 1234abcd

	printf("%d\n",ft_printf("www %X mmm %%%%\n", u));
//	ft_printf("www %p mmm\n", i);
//	printf("%x\n", 123);
}*/
