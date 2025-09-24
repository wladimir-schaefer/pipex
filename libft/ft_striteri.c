/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:26:28 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/22 10:26:31 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned char	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

// Function that uppercases letters at even indices
void to_upper_even(unsigned int i, char *c)
{
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

// Function that replaces each character with its index + '0' (only for digits)
void replace_with_index(unsigned int i, char *c)
{
    if (i < 10)
        *c = '0' + i;
}

// Function that prints character and its index (doesn't modify string)
void print_index_and_char(unsigned int i, char *c)
{
    printf("Index %u: %c\n", i, *c);
}
int main(void)
{
    char test1[] = "hello world";
    char test2[] = "abcdef";
    char test3[] = "1234567890";

    printf("Test 1 - to_upper_even:\nBefore: %s\n", test1);
    ft_striteri(test1, to_upper_even);
    printf("After : %s\n\n", test1);  // Expect: "HeLlO WoRlD"

    printf("Test 2 - replace_with_index:\nBefore: %s\n", test2);
    ft_striteri(test2, replace_with_index);
    printf("After : %s\n\n", test2);  // Expect: "012345"

    printf("Test 3 - print_index_and_char:\n");
    ft_striteri(test3, print_index_and_char); // Prints each char with its index
    printf("After : %s\n", test3);  // Unchanged: "1234567890"

    return 0;
}
*/