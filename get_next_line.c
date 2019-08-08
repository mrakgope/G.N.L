/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrakgope <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 11:01:38 by mrakgope          #+#    #+#             */
/*   Updated: 2019/08/08 16:07:10 by mrakgope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		newline(char **line, char **str)
{
	char		*ptr;
	char		*ptr1;
	char		*sch;

	ptr = *str;
	ptr1 = *str;
	sch = ft_strchr(ptr, '\n');
	*line = ft_strsub(ptr, 0, sch - ptr);
	while (*ptr)
		ptr++;
	sch++;
	*str = ft_strsub(ptr1, sch - ptr1, ptr - sch);
	free(ptr1);
	return (1);
}

int				end_line(char **line, char **str)
{
	if (*str && ft_strlen(*str) > 0)
	{
		*line = *str;
		*str = NULL;
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static	char	*q[100];
	char			str[BUFF_SIZE + 1];
	char			*ptr;
	int				i;

	if (line && fd >= 0 && read(fd, str, 0) == 0)
	{
		if (q[fd] != NULL && ft_strchr(q[fd], '\n'))
			return (newline(line, &q[fd]));
		while ((i = read(fd, str, BUFF_SIZE)) > 0)
		{
			if (q[fd] == NULL)
				q[fd] = ft_strdup("");
			str[i] = '\0';
			ptr = q[fd];
			q[fd] = ft_strjoin(ptr, str);
			free(ptr);
			if (ft_strchr(q[fd], '\n') != NULL)
				return (newline(line, &q[fd]));
		}
		return (end_line(line, &q[fd]));
	}
	return (-1);
}
