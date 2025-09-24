/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wschafer <wschafer@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:34:16 by wschafer          #+#    #+#             */
/*   Updated: 2025/05/17 21:40:10 by wschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
	int *arr1;
	size_t count1 = 5;

	arr1 = (int *)ft_calloc(count1, sizeof(int));
	if (!arr1)
		printf("Error");
	for (size_t i = 0; i < count1; i++)
		printf("str[%zu] = %d\n", i, arr1[i]);	
	free(arr1);
	printf("\n");

	char *arr2;
	size_t count2 = 5;

	arr2 = (char *)ft_calloc(count2, sizeof(char));
	if (!arr2)
		printf("Error");
	for (size_t i = 0; i < count2; i++)
		printf("str[%zu] = %d\n", i, arr2[i]);
	free(arr2);
	printf("\n");

	int *arr3;
	size_t count3 = 0;

	arr3 = (int *)ft_calloc(count3, SIZE_MAX);
	if (!arr3)
	{
		printf("Error\n");
		return (1);
	}
	for (size_t i = 0; i < count3; i++)
		printf("str[%zu] = %d\n", i, arr3[i]);	
	free(arr3);
}
*/