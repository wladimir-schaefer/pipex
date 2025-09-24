/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:44:52 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/21 13:44:57 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*res;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h" // Include your ft_strmapi prototype

// Example function to use with ft_strmapi
char to_upper_even(unsigned int i, char c)
{
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return c - 32; // Convert to uppercase
    return c;
}

int main(void)
{
    const char *input = "libfttest";
    char *result = ft_strmapi(input, to_upper_even);

    if (result)
    {
        printf("Original: %s\n", input);
        printf("Mapped  : %s\n", result);
        free(result); // Always free memory returned by ft_strmapi
    }
    else
    {
        printf("ft_strmapi returned NULL\n");
    }
    return 0;
}
*/