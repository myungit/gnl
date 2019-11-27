/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:29:38 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/27 23:33:25 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_list	*give_me_head(int fd, char *buff, t_list *headlst)
{
	if (!headlst)
		headlst = ft_lstnew(fd, buff);
	return (headlst);
}

static int		copyline(t_list *headlst, char **line, char *buff)
{
	char	*tmp_line;
	char	*start;
	int 	size;

	size = 0;
	if (!buff)
		return (-1);
	while (buff[size] != '\n' && buff[size])
		size++;
	tmp_line = (char *)malloc(sizeof(char) * size);
	tmp_line[size] = 0;
	start = tmp_line;
	while (size--)
		*tmp_line++ = *buff++;
	*line = start;
	headlst->content = ++buff;
	free(start);
	if (*buff != '\n' && *buff)
		return (0);
	return (1);
}

#include <string.h>
int		get_next_line(int fd, char **line)
{
	static	t_list *headlst;	
	//t_list	nextlst;
	char	*buff;
	int		size;
	int		result;

	if (fd < 0)
		return (fd);
	if ((buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		if ((size = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[size] = 0;
			headlst = give_me_head(fd, buff, headlst);
			result = copyline(headlst, line, buff);
			printf("my buff: %s\n", buff);
			printf("line: %s\n", *line);
			printf("content: %s\n", headlst->content);
			return (result);
		}
	}
	if (!line)
	{
		return (0);
	}
	return (1);
}
#include <fcntl.h>
int main(void)
{
	char *hi;
	int fd;

	fd = open("hola.txt", O_RDONLY);
	printf("%d\n", fd);
	printf("result: %d\n", get_next_line(fd, &hi));
	printf("result: %d\n", get_next_line(fd, &hi));
}
