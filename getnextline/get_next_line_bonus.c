/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:33:39 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/29 17:22:19 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		delete_element(t_remain *active, t_remain **head)
{
	t_remain *aux;
	t_remain *prev;

	aux = *head;
	if (active->fd == aux->fd)
	{
		*head = aux->next;
		free(aux);
	}
	else
	{
		while (aux && aux->fd != active->fd)
		{
			prev = aux;
			aux = aux->next;
		}
		if (!aux)
			return ;
		prev->next = aux->next;
		free(aux);
	}
}

int			get_lines(char **line, t_remain *active, t_remain **head)
{
	if (active->content && ft_strchr(active->content, '\n'))
	{
		*line = copy_line(&active->content);
		return (1);
	}
	if (active->content)
	{
		*line = active->content;
		delete_element(active, &*head);
	}
	return (0);
}

t_remain	*find_fd(t_remain **head, int fd)
{
	t_remain *active;

	if (!*head)
	{
		*head = ft_lstnew(fd);
		active = *head;
		return (active);
	}
	active = *head;
	while (active)
	{
		if (active->fd == fd)
			break ;
		active = active->next;
	}
	if (!active)
	{
		active = *head;
		while (active->next)
			active = active->next;
		active->next = ft_lstnew(fd);
		active = active->next;
	}
	return (active);
}

int			get_next_line(int fd, char **line)
{
	static t_remain	*head;
	char			*buf;
	t_remain		*active;
	int				i;

	if (fd < 0 || !line)
		return (-1);
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	active = find_fd(&head, fd);
	while ((i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		active->content = ft_strjoin(active->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (i < 0)
		return (-1);
	free(buf);
	return (get_lines(&*line, active, &head));
}
