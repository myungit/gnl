/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:23:05 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/12/25 17:23:15 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list		*ft_position_list(t_list *move_lst, int fd)
{
	if (move_lst->fd != fd)
	{
		while (move_lst->next && (move_lst->fd != fd))
			move_lst = move_lst->next;
		if (move_lst->fd != fd)
		{
			move_lst->next = ft_lstnew(fd, ft_strdup(""));
			move_lst = move_lst->next;
		}
	}
	return (move_lst);
}

int			ft_read_line(t_list *move_lst, int fd, char *buff, char **line)
{
	int		result;
	char	*tmp;
	char	*after;

	while ((result = (read(fd, buff, BUFFER_SIZE))) >= 0)
	{
		buff[result] = 0;
		tmp = ft_strjoin(move_lst->content, buff);
		if ((after = ft_strchr(tmp, '\n')))
		{
			*after++ = '\0';
			*line = ft_strdup(tmp);
			move_lst->content = ft_strdup(after);
			free(tmp);
			return (1);
		}
		if (result == 0)
		{
			*line = ft_strdup(tmp);
			free(tmp);
			return (0);
		}
		move_lst->content = tmp;
	}
	return (-1);
}

void		ft_clearlist(t_list **head_lst, t_list *move_lst)
{
	t_list			*tmp;
	t_list			*erase;

	tmp = *head_lst;
	if (tmp->fd == move_lst->fd)
	{
		*head_lst = tmp->next;
		free(tmp);
	}
	else
	{
		while (tmp && ((tmp->next)->fd != move_lst->fd))
			tmp = tmp->next;
		if ((tmp->next)->fd == move_lst->fd)
		{
			erase = tmp->next;
			tmp->next = move_lst->next;
			free(erase);
		}
	}
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
		head_lst = ft_lstnew(fd, ft_strdup(""));
	move_lst = ft_position_list(head_lst, fd);
	result = (ft_read_line(move_lst, fd, buff, line));
	if (result < 1)
		ft_clearlist(&head_lst, move_lst);
	return (result);
}
