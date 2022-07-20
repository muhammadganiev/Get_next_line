/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <gf.black.tv@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:31:37 by muganiev          #+#    #+#             */
/*   Updated: 2022/07/20 19:19:32 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	
}

int	f1(int *j)
{
	*j = *j * 2;
	return (*j);
}

int	main(void)
{
	int	i;

	i = 5;
	f1(&i);
	printf("%d\n", i);
}
