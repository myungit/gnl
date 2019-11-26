/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:29:38 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/26 19:12:19 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_list	*give_me_head(int fd, char *buff, t_list *headlst)
{
	if (!headlst)
		headlst = ft_lstnew(fd, buff);
	return (headlst);
}

int		get_next_line(int fd, char **line)
{
	static t_list *headlst;	
	char	*buff;
	int	i;

	i = 0;

	if (!fd)
		return (fd);
	if ((buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
	{
		read(fd, buff, BUFFER_SIZE);
		headlst = give_me_head(fd, buff, headlst);
		while (buff[i] != '\n' && buff[i])
		{
			buff[i] = line[0][i];
			printf("%c", line[0][i]);
			i++;
		}
		line[0][i] = 0;
		buff[i] = 0;
	}
	if (!line)
		return (0);
	i = 0;
	while (line[0][i])
		printf("%c\n", line[0][i++]);
	return (1);
}
#include <fcntl.h>
int main(void)
{
	char **hi = malloc(sizeof(char*) * 500);
	*hi = malloc(sizeof(char) * 500);
	int fd;

	printf("%d\n", BUFFER_SIZE);
	fd = open("hola.txt", O_RDONLY);
	get_next_line(fd, hi);
}
