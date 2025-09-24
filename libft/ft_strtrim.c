/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:58:16 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/19 10:58:20 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = malloc((end - start + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, &s1[start], end - start + 1);
	trimmed[end - start] = '\0';
	return (trimmed);
}
/*
#include <stdio.h>
int main(void)
{
	char const *src = "bc123ab";
	char const *set = "abc";
	

	printf("src: %s\n", src);
	printf("set: %s\n", set);

	char	*trimmed = ft_strtrim(src, set);
	printf("trimmed: %s\n", trimmed);

	free (trimmed);
	return 0;
}
*/