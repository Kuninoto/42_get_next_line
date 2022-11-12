/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:47:05 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/12 00:58:29 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
	{
		if (!str[i])
			return (0);
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	char				*mem_allocated;
	unsigned int		total;
	size_t				i;

	total = nitems * size;
	mem_allocated = malloc(nitems * size);
	if (mem_allocated == NULL)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		mem_allocated[i] = '\0';
		total--;
		i++;
	}
	return ((void *)mem_allocated);
}