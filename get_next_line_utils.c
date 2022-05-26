/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:22:45 by krochefo          #+#    #+#             */
/*   Updated: 2022/05/26 08:46:02 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		joined_len;
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	joined_len = ft_strlen(s1) + ft_strlen(s2);
	rtn = malloc(sizeof(char) * (joined_len + 1));
	if (!rtn || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		rtn[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		rtn[i] = s2[j];
		i++;
		j++;
	}
	rtn[joined_len] = 0;
	return (rtn);
}

char	*ft_strchr(const char *string, int str_char)
{
	char	*str;

	str = (char *)string;
	while (*str != str_char && *str != 0)
		str++;
	if (*str == str_char)
		return (str);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*rtn;

	rtn = malloc(size * count);
	if (!rtn)
		return (NULL);
	ft_bzero(rtn, size * count);
	return (rtn);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
