/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:29:38 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/12/08 21:06:14 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*static char		*ft_strndup(const char *s1, int len)
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
*/
static char		*ft_strdup(char *s1)
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
/*
static int		copyline(char **line, char *buff, int fd, t_list **head_lst)
{
	int		size;

	if (*head_lst)
		buff = ft_strjoin((*head_lst)->content, buff);
	size = 0;
	while (buff[size] != '\n' && buff[size])
		size++;
	*line = ft_strndup(buff, size);
	if (buff[size])
	{
		if (buff[size] == '\n')
		{
			*head_lst = ft_lstnew(fd, &buff[++size]);
			return (1);
		}
		*head_lst = ft_lstnew(fd, &buff[++size]);
	}
	*head_lst = ft_lstnew(fd, &buff[size]);
	return (0);
}
*/

int				get_next_line(int fd, char **line)
{
	static t_list	*head_lst;
	t_list			*move_lst;
	char			buff[BUFFER_SIZE + 1];
	char			*after;
	int				result;

	result = 0;
	if (fd < 0 || !line || BUFFER_SIZE < 0)
		return (-1);
	if (!head_lst)
		head_lst = ft_lstnew(fd, "");
	move_lst = head_lst;
	while ((read(fd, buff, BUFFER_SIZE)))
	{
		buff[BUFFER_SIZE] = 0;
		while (move_lst->next && (move_lst->fd != fd))
			move_lst = move_lst->next;
		if (move_lst->fd != fd)
		{
			move_lst->next = ft_lstnew(fd, buff);
			move_lst = move_lst->next;
		}
		move_lst->content = ft_strjoin(move_lst->content, buff);
		if ((after = ft_strchr(move_lst->content, '\n')))
		{
			*after++ = '\0';
			result = 1;
		}
		if (result)
		{
			*line = move_lst->content;
			move_lst->content = ft_strdup(after);
			return (result);
		}
	}
	*line = ft_strdup("");
	return (0);
}

#include <fcntl.h>
int main()
{
	int fd;
	char c;
	int	i;
	char *line;

	fd = open("hola.txt", O_RDONLY);
	printf("%d\n", get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("line : %s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("line : %s\n", line);
	c = 0;
	i = 0;
	//while (c != 126)
	//	printf("i: %d char: %c\n", i++ ,c++);
}
