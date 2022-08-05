/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <gf.black.tv@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:32:26 by muganiev          #+#    #+#             */
/*   Updated: 2022/08/05 20:51:01 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
# endif

void	*ft_memcpy(void *dest, const void *src, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
int		ft_strlen(const char *p);
char	*line_num(const char *s);
char	*get_next_line(int fd);

#endif
