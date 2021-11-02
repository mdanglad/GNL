/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanglad <mdanglad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:22:18 by mdanglad          #+#    #+#             */
/*   Updated: 2021/10/31 20:00:38 by mdanglad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
#define malloc test

void*	test(int x);
char	*get_next_line(int fd);
char	*trim_static(char *str, char *line, int ret);
size_t	new_line_flag(char *str);
size_t	len(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif
