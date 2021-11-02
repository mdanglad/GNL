/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanglad <mdanglad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:42:29 by mdanglad          #+#    #+#             */
/*   Updated: 2021/10/31 19:37:38 by mdanglad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	len(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (ft_strdup(s2));
	str = (char *)malloc(sizeof(char) * len(s1) + len(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*trim_static(char *str, char *line, int ret)
{
	int	len_str;
	int	len_line;
	int	new_len;
	char	*new_str;

	len_str = len(str);
	len_line = len(line);
	new_len = len_str - len_line;
	if (ret == 0 || new_len == 0)
	{
		free(str);
		return (NULL);
	}	
	new_str = malloc(sizeof(char) * new_len + 1);
	if (!new_str)
		return (NULL);
	len_str = 0;
	while (str[len_line] != '\0')
		new_str[len_str++] = str[len_line++];
	new_str[len_str] = '\0';
	free(str);
	return (new_str);
}
