/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:29:38 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/12/07 23:14:33 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char		*ft_strndup(const char *s1, int len)
{
	char	*s2;
	int		i;

	s2 = (char*)malloc(sizeof(char) * len + 1);
	s2[len + 1] = 0;
	i = 0;
	if (s2)
	{
		while (i <= len)
		{
			s2[i] = s1[i];
			i++;
		}
		return (s2);
	}
	return (0);
}

static int		copyline(char **line, char *buff, int fd, t_list **saved_lst)
{
	int		size;

	if (*saved_lst)
		buff = ft_strjoin((*saved_lst)->content, buff);
	size = 0;
	while (buff[size] != '\n' && buff[size])
		size++;
	*line = ft_strndup(buff, size);
	if (buff[size])
	{
		if (buff[size] == '\n')
		{
			*saved_lst = ft_lstnew(fd, &buff[++size]);
			return (1);
		}
		*saved_lst = ft_lstnew(fd, &buff[++size]);
	}
	*saved_lst = ft_lstnew(fd, &buff[size]);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*saved_lst;
	char			*buff;
	int				i;
	int				result;

	if (fd <= 0)
		return (fd);
	if ((buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		while ((i = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[i] = 0;
			result = copyline(line, buff, fd, &saved_lst);
			free(buff);
			if (!result)
				break;
		}
		return (result);
	}
	return (0);
}
