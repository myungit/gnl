/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:24:17 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/12/25 17:24:23 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int				get_next_line(int fd, char **line);
typedef struct	s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(int fd, void *content);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *s);
char			*ft_strdup(char *s1);
char			*ft_strchr(const char *s, int c);
#endif
