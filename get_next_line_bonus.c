/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <gf.black.tv@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:31:37 by muganiev          #+#    #+#             */
/*   Updated: 2022/08/05 19:09:44 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Удаляет лишнее

char	*cutting(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	buff = malloc (sizeof(char) * (ft_strlen(str) - i + 1));
	if (!buff)
		return (0);
	j = 0;
	i++;
	while (str[i])
	{
		buff[j++] = str[i++];
	}
	buff[j] = '\0';
	free(str);
	return (buff);
}

// Возвращает строку + \0

char	*new_line(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	buff = malloc(sizeof(char) * (i + 2));
	if (!buff)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		buff[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

// Читает весь текст в static

static char	*reader(int fd, char *str)
{
	char	*buff;
	int		readed_bytes;

	readed_bytes = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (!line_num(str) && readed_bytes != 0)
	{
		readed_bytes = read(fd, buff, BUFFER_SIZE);
		if (readed_bytes == -1)
		{
			free(buff);
			return (0);
		}
		buff[readed_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str[1024];
	char			*buff;

	if (fd < 0 || fd >= 1024|| BUFFER_SIZE <= 0)
		return (0);
	str[fd] = reader(fd, str[fd]);
	if (!str[fd])
		return (0);
	buff = new_line(str[fd]);
	str[fd] = cutting(str[fd]);
	return (buff);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int		fd;

// 	fd = open("input.txt", O_RDONLY);
// 	char ihab [] = "IHAB LOH";
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
