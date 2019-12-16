/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpark-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:33:58 by mpark-ki          #+#    #+#             */
/*   Updated: 2019/12/16 21:10:02 by mpark-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*ft_lstnew(int fd, void *content)
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

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	if (!(s2 = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (0);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*start;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(result = (char*)malloc(sizeof(char) * len)))
		return (0);
	start = result;
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = 0;
	return (start);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (*s++ == '\0')
			return (0);
	return ((char *)s);
}
