/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:29:38 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/26 18:59:55 by mpark-ki         ###   ########.fr       */
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
			buff[i] = *line[i];
			i++;
		}
		*line[i] = 0;
		buff[i] = 0;
		line++;
	}
	if (!line)
		return (0);
	while (line)
		printf("%s\n", *line++);
	return (1);
}

int main(void)
{
	char **hi = NULL;

	printf("%d\n", BUFFER_SIZE);
	printf("%d\n", get_next_line(3, hi));
}
