/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:22:45 by krochefo          #+#    #+#             */
/*   Updated: 2022/05/25 10:24:13 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_concatstr(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*str3;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str3 = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	str3 = str1;
	while (str3[i])
		i++;
	while (str2[j])
	{
		str3[i] = str2[j];
		i++;
		j++;
	}
	str3[i] = '\0';
	return (str3);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_buffcut(char *str, int input, int len)
{
	int		i;
	int		j;
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp2 = NULL;
	i = 0;
	j = 0;
	while (str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	while (i <= len)
	{
		temp2[j] = str[i];
		j++;
		i++;
	}
	if (input == 1)
		return (temp);
	else
		return (temp2);
}
