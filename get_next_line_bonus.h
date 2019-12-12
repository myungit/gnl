/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myntcake <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:18:55 by myntcake          #+#    #+#             */
/*   Updated: 2019/12/12 18:19:03 by myntcake         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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
