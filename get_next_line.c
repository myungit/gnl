/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:29:38 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/12/08 23:30:07 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char		*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	s2 = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	s2[ft_strlen(s1) + 1] = 0;
	i = 0;
	if (s2)
	{
		while (i <= ft_strlen(s1))
		{
			s2[i] = s1[i];
			i++;
		}
		return (s2);
	}
	return (0);
}

t_list		*ft_position_list(t_list *move_lst, int fd)
{
	while (move_lst->next && (move_lst->fd != fd))
		move_lst = move_lst->next;
	if (move_lst->fd != fd)
	{
		move_lst->next = ft_lstnew(fd, "");
		move_lst = move_lst->next;
	}
	return (move_lst);
}

int			ft_read_line(t_list *move_lst, int fd, char *buff, char **line)
{
	int		result;
	char	*after;

	while ((result = (read(fd, buff, BUFFER_SIZE))) >= 0)
	{
		buff[result] = 0;
		move_lst->content = ft_strjoin(move_lst->content, buff);
		if ((after = ft_strchr(move_lst->content, '\n')))
		{
			*after++ = '\0';
			*line = move_lst->content;
			move_lst->content = ft_strdup(after);
			return (1);
		}
		if (result == 0)
		{
			*line = move_lst->content;
			move_lst->content = ft_strdup("");
			return (0);
		}
	}
	return (-1);
}

int			get_next_line(int fd, char **line)
{
	static t_list	*head_lst;
	t_list			*move_lst;
	char			buff[BUFFER_SIZE + 1];
	int				result;

	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	if (!head_lst)
		head_lst = ft_lstnew(fd, "");
	move_lst = head_lst;
	move_lst = ft_position_list(move_lst, fd);
	result = ft_read_line(move_lst, fd, buff, line);
	return (result);
}

#include <fcntl.h>
int			main(void)
{
	int fd;
	int fd2;
	int fd3;
	char c;
	int	i;
	char *line;

	fd = open("hola.txt", O_RDONLY);
	fd2 = open("hola2.txt", O_RDONLY);
	fd3 = open("hola3.txt", O_RDONLY);
	printf("fd1 %d\n", get_next_line(fd, &line));
	printf("fd1 line : %s\n", line);
	printf("fd2: %d\n", get_next_line(fd2, &line));
	printf("fd2: line : %s\n", line);
	printf("fd1 %d\n", get_next_line(fd, &line));
	printf("fd1 line : %s\n", line);
	printf("fd2: %d\n", get_next_line(fd2, &line));
	printf("fd2: line : %s\n", line);
	printf("fd1 %d\n", get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("fd1 %d\n", get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("fd2: %d\n", get_next_line(fd2, &line));
	printf("fd2: line : %s\n", line);
	printf("fd2: %d\n", get_next_line(fd2, &line));
	printf("fd2: line : %s\n", line);
	printf("fd2: %d\n", get_next_line(fd2, &line));
	printf("fd2: line : %s\n", line);
	printf("fd1 %d\n", get_next_line(fd, &line));
	printf("fd1 line : %s\n", line);
	printf("fd1 %d\n", get_next_line(fd, &line));
	printf("fd1 line : %s\n", line);
	printf("fd3 %d\n", get_next_line(fd3, &line));
	printf("fd3 line : %s\n", line);
	printf("fd3 %d\n", get_next_line(fd3, &line));
	printf("fd3 line : %s\n", line);
	printf("fd3 %d\n", get_next_line(fd3, &line));
	printf("fd3 line : %s\n", line);
	printf("fd3 %d\n", get_next_line(fd3, &line));
	printf("fd3 line : %s\n", line);
	printf("fd3 %d\n", get_next_line(fd3, &line));
	printf("fd3 line : %s\n", line);
	printf("fd3 %d\n", get_next_line(fd3, &line));
	printf("fd3 line : %s\n", line);
	printf("fd3 %d\n", get_next_line(fd3, &line));
	printf("fd3 line : %s\n", line);
	printf("fd3 %d\n", get_next_line(fd3, &line));
	printf("fd3 line : %s\n", line);
	printf("fd3 %d\n", get_next_line(fd3, &line));
	printf("fd3 line : %s\n", line);
	printf("should be%d\n", get_next_line(18000, &line));
	printf("line : %s\n", line);
	c = 0;
	i = 0;
	//while (c != 126)
	//	printf("i: %d char: %c\n", i++ ,c++);
}
