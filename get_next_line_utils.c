/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:33:58 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/26 18:56:54 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(int fd, void *content)
{
	t_list	*tmp;

	if ((tmp = (t_list *)malloc(sizeof(t_list))))
	{
		tmp->fd = fd;
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}

