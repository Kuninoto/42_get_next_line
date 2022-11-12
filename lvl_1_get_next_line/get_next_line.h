/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 00:47:03 by nnuno-ca          #+#    #+#             */
/*   Updated: 2022/11/12 01:54:51 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif 

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strchr(const char *str, int c);
char	*join_n_free(char *global_buf, char *buff);
void	*ft_calloc(size_t nitems, size_t size);

#endif
