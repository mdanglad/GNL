/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanglad <mdanglad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:29:47 by mdanglad          #+#    #+#             */
/*   Updated: 2021/11/02 17:59:05 by ramzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	length;

	length = len(s1);
	if (length == 0)
		return (NULL);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	length = 0;
	while (s1[length] != '\0')
	{
		str[length] = s1[length];
		length++;
	}
	str[length] = '\0';
	return (str);
}

char	*line_filler(char *str, char *line)
{
	size_t	i;

	i = 0;
	if (line == NULL || str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] != 0)
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

size_t	new_line_flag(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		if (str[i++] == '\n')
			return (1);
	return (0);
}

char	*malloc_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (new_line_flag(str) == 1)
	{
		while (str[i] != '\n')
			i++;
		line = (char *)malloc(sizeof(char) * (i + 2));
		if (!line)
			return (NULL);
	}
	else
	{
		while (str[i] != '\0')
			i++;
		line = (char *)malloc(sizeof(char) * (i + 1));
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*str;
	char		*line;
	int			ret;

	line = NULL;
	ret = 1;
	if (fd < 0)
		return (NULL);
	while (new_line_flag(str) == 0 && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buf[ret] = 0;
		str = ft_strjoin(str, buf);
	}
	if (str)
	{
		line = malloc_line(str);
		line = line_filler(str, line);
		str = trim_static(str, line, ret);
		return (line);
	}
	return (NULL);
}
