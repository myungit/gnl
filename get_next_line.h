/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:32:45 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/11/27 20:41:07 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
int				get_next_line(int fd, char **line);
typedef struct s_list
{
	int				fd;
	void			*content;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(int fd, void *content);
#ifndef BUFFER_SIZE
# define BUFFFER_SIZE 8
#endif
#endif
