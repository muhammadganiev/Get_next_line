/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <gf.black.tv@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:51:05 by muganiev          #+#    #+#             */
/*   Updated: 2022/08/04 19:34:21 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

char	*get_next_line(int fd)
{
	static char	buf[15];
	char		*line;
	int			i;

	i = 0;
	if (buf[i] == '\0')
	{
		read (fd, buf, 14);
	}
	buf[14] = '\0';
	while (buf[i] && buf[i] != ' ')
	{
		printf("%c", buf[i]);
		i++;
	}
	printf("\n");
	return (buf);
}

int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
