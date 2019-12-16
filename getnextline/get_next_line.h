/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:36:02 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/29 17:19:31 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_remain
{
	char			*content;
	int				fd;
	struct s_remain	*next;
}					t_remain;

int					get_next_line(int fd, char **line);
int					get_lines(char **line, t_remain *active, t_remain **head);

void				*ft_calloc(size_t count, size_t size);
void				delete_element(t_remain *active, t_remain **head);

t_remain			*ft_lstnew(int fd);
t_remain			*find_fd(t_remain **head, int fd);

char				*copy_line(char **s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char *s1, const char *s2);

#endif
