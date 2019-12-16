/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:32:54 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/12/16 17:27:12 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			*line = (move_lst->content);
			move_lst->content = (*after) ? ft_strdup(after) : ft_strdup("");
			return (1);
		}
		if (result == 0)
		{
			*line = move_lst->content;
			move_lst->content = ft_strdup("");
			return (0);
		}
	}
	*line = ft_strdup("");
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
	result = (ft_read_line(move_lst, fd, buff, line));
	if (result == -1)
		free(move_lst);
	return (result);
}
