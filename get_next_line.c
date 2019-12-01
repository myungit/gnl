/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:29:38 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/12/01 20:16:13 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int		copyline(char **line, char *buff)
{
	char	*tmp_line;
	char	*start;
	int 	size;

	if (!buff)
		return (-1);
	size = 0;
	while (buff[size] != '\n' && buff[size])
		size++;
	tmp_line = (char *)malloc(sizeof(char) * size);
	tmp_line[size] = 0;
	start = tmp_line;
	while (size--)
		*tmp_line++ = *buff++;
	*line = start;
	free(start);
	printf("first cut line:%s\n", *line);
	if (*buff != '\n')
		return (0);
	return (1);
}

static int		copycache(char *cache, char *buff)
{
	int		size;

	size = 0;
	printf("%d", ft_strlen(buff));
	printf("cache cut buff:%s\n", buff);
	if (!cache)
	{
		if ((cache = (char *)malloc(sizeof(char) * ft_strlen(buff))))
			while (*buff)
			{
				cache[size] = *buff++;
			}
	}
	printf("what is buff: %c\n", *buff);
	printf("what is cache: %s\n", cache);
	return (1);
}

#include <string.h>
int		get_next_line(int fd, char **line)
{
	static char	*line_cache;	
	char		*buff;
	int			size;
	int			result;

	if (fd < 0)
		return (fd);
	if ((buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		if ((size = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[size] = 0;
			result = copyline(line, &(*buff));
			copycache(line_cache, &(*buff));
			printf("my buff: %s\n", buff);
			printf("line: %s\n\n", *line);
			printf("content: %s\n", line_cache);
			return (result);
		}
	}
	return (0);
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
	printf("result: %d\n", get_next_line(fd, &hi));
}
