/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:47:05 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/06 02:12:17 by nnuno-ca         ###   ########.fr       */
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
};

void	copy_until_null(const char *src, char *dest)
{
	if (!src || !dest)
		return ;
	size_t	i;
	
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}