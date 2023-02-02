/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skaragul <skaragul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:27:52 by skaragul          #+#    #+#             */
/*   Updated: 2023/01/26 17:13:32 by skaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	arr = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[j] != '\0')
		arr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		arr[i++] = s2[j++];
	arr[i] = '\0';
	free(s1);
	return (arr);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (0);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_new_str(char *s)
{
	int		i;
	int		slen;
	char	*newl;

	i = 0;
	slen = ft_strlen(s);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (0);
	}
	newl = (char *)malloc(sizeof(char) * (slen - i) + 1);
	if (!newl)
		return (0);
	slen = 0;
	i++;
	while (s[i] != '\0')
		newl[slen++] = s[i++];
	newl[slen] = '\0';
	free(s);
	return (newl);
}
