/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:54:00 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/19 12:54:05 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dsize);
static	size_t	words(char const *w, char c);
static	size_t	putword(char **arr, char const *s, size_t i, char c);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**arr;

	arr = malloc((words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s && *s == c)
			s++;
		else 
		{
			s += putword(arr, s, i, c);
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

static	size_t	putword(char **arr, char const *s, size_t i, char c)
{
	size_t	len_str;

	len_str = 0;
	while (s[len_str] && s[len_str] != c)
		len_str++;
	arr[i] = malloc((len_str + 1) * sizeof(char));
	if (!arr[i])
	{
		while (i > 0)
			free (arr[--i]);
		free (arr);
		return (0);
	}
	ft_strlcpy(arr[i], s, len_str + 1);
	return (len_str);
}

static	size_t	words(char const *s, char c)
{
	size_t	count;
	size_t	in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}
/*
#include <stdio.h>
int main(void)
{
	char const *src = "asd   123     sdf   ";
	char c = ' ';
	size_t	i = 0;

	printf("src: %s\n", src);
	printf("delimeter: %c\n", c);

	char	**splitted = ft_split(src, c);
	
	while (splitted[i])
	{
		printf("str: %s!\n", splitted[i]);
		i++;
	}
	printf("str: %s\n", splitted[i]);
	while (i > 0)
		free (splitted[--i]);
	free (splitted);
	return 0;
}
*/