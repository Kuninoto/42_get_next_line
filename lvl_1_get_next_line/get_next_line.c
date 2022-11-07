/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:47:06 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/07 00:51:48 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

/* #define dummy_nr_strings 10

#include <stdio.h>
#include <fcntl.h> */

char	*get_next_line(int fd)
{
	char	buffer[1];
	char	line[ARRAY_MAX_SIZE];
	char	*malloced_line;
	int		read_status;
	/* static */ size_t	i;

	if (fd < 0)
		return (NULL);
	buffer[0] = '\0';
	i = 0;
	while (buffer[0] != '\n')
	{
		read_status = read(fd, buffer, 1);
		if (read_status == -1)
			return (NULL);
		else if (read_status == 0)
			break ;
		line[i++] = buffer[0];
	}
	line[i] = '\0';
	malloced_line = malloc(ft_strlen(line) * sizeof(char));
	copy_until_null(line, malloced_line);
	return (malloced_line);
}

/* // MANDATORY MAIN
int main(void)
{
// STDIN test

	char *read_stdin = get_next_line(STDIN_FILENO);
	
	printf("LINE READ =  %s", read_stdin);
	for (size_t i = 0; i < ft_strlen(read_stdin); i++)
	{
		if (read_stdin[i] == '\n')
			printf("read_stdin[%ld] = '\\n'", i);
		else
			printf("read_stdin[%ld] = '%c'\n", i, read_stdin[i]);
	}
	printf("\n");

	
// One line file test
	int txt_fd = open("test.txt", O_RDONLY);
	char *read_txt = get_next_line(txt_fd);

	printf("LINE READ =  %s\n", read_txt);
	for (size_t i = 0; i < ft_strlen(read_txt); i++)
	{
		if (read_txt[i] == '\n')
			printf("read_txt[%ld] = '\\n'", i);
		else
			printf("read_txt[%ld] = '%c'\n", i, read_txt[i]);
	}
	close(txt_fd);

	
// Multiple line File Test
	int 	txt_fd = open("test.txt", O_RDONLY);
	char	*line = get_next_line(txt_fd);
	char	**matrix = malloc((dummy_nr_strings + 1) * sizeof(char *));
	
	int i = 0;
	while (line[0] != '\0')
	{
		matrix[i++] = line;
		line = get_next_line(txt_fd);
		printf("i = %d\n", i);
	}	
	matrix[i] = NULL;

	for (int j = 0; matrix[j] != NULL; j++)
		printf("matrix[%d] = %s", j, matrix[j]);
	close(txt_fd);

	return (0);
} */