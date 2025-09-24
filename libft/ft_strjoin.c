/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:49:09 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/19 10:49:14 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;
	char	*res;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char const	*str1 = "abc";
	char const	*str2 = "def";
	char		*res;

	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
	res = ft_strjoin(str1, str2);
	printf("res:  %s\n", res);
}
*/
/*
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
*/