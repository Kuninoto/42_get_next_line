/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:55:52 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/12 17:38:31 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

bool	ft_strchr(const char *str, int ch)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == ch)
			return (true);
	}
	return (false);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	size_t	i;
	char	*alloced;

	total = nmemb * size;
	i = 0;
	alloced = malloc(total);
	if (!alloced)
		return (NULL);
	while (total-- > 0)
		alloced[i++] = '\0';
	return ((void *)alloced);
}
