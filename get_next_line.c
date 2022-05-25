/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:22:13 by krochefo          #+#    #+#             */
/*   Updated: 2022/05/25 12:47:03 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*buff;
	char		*finalstr;
	static char	*overstr;
	size_t		read_len;
	int			i;

	i = -1;
	buff = NULL;
	finalstr = NULL;
	read_len = 0;
	while (finalstr[i++] != '\n')
	{
		if (overstr != NULL)
			finalstr = overstr;
		read_len += read(fd, buff, BUFFER_SIZE);
		ft_concatstr(finalstr, buff);
	}
	overstr = ft_buffcut(finalstr, 1, read_len);
	finalstr = ft_buffcut(finalstr, 2, read_len);
	return (finalstr);
	if (read_len == '0')
	{
		overstr = NULL;
		return (NULL);
	}
}
