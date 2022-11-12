/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:52:05 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/12 01:48:13 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_printed(char *global_buf)
{
	size_t	i;
	size_t	j;
	char	*new_global;

	i = 0;
	j = 0;
	while (global_buf[i] && global_buf[i] != '\n')
		i++;
	if (!global_buf[i])
	{
		free(global_buf);
		return (NULL);
	}
	new_global = malloc(((ft_strlen(global_buf) - i) + 1) * sizeof(char));
	if (!new_global)
		return (NULL);
	i++;
	j = 0;
	while (global_buf[i])
		new_global[j++] = global_buf[i++];
	new_global[j] = '\0';
	free(global_buf);
	return (new_global);
}

char	*get_line(char *global_buf)
{
	size_t	len;
	size_t	i;
	char	*line;

	len = 0;
	i = 0;
	if (!global_buf)
		return (NULL);
	while (global_buf[len] != '\n' && global_buf[len])
		len++;
	line = malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (i <= len)
	{
		line[i] = global_buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*join_n_free(char *global_buf, char *buff)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*final_str;
	size_t	i;
	size_t	j;

	if (!global_buf || !buff)
		return (NULL);
	len_s1 = ft_strlen(global_buf);
	len_s2 = ft_strlen(buff);
	final_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (final_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len_s1)
		final_str[i++] = global_buf[j++];
	j = 0;
	while (j < len_s2)
		final_str[i++] = buff[j++];
	final_str[i] = '\0';
	free(global_buf);
	return (final_str);
}

char	*read_buffsize(int fd, char *global_buffer)
{
	int		bytes_read;
	char	*buffer;
	
	if (global_buffer == NULL)
		global_buffer = ft_calloc(1, sizeof(char));
	bytes_read = 1;
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		global_buffer = join_n_free(global_buffer, buffer);
		if (ft_strchr(global_buffer, '\n') != 0)
			break ;
	}
	free(buffer);
	return (global_buffer);
}

char	*get_next_line(int fd)
{
	static char	*global_buffer;
	char		*line;
	
	if (fd < 0 || read(fd, NULL, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	global_buffer = read_buffsize(fd, global_buffer);
	if (!global_buffer)
		return (NULL);
	line = get_line(global_buffer);
	global_buffer = clean_printed(global_buffer);
	return (line);
}
