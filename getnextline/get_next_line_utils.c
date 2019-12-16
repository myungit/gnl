/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:41:08 by mpernia-          #+#    #+#             */
/*   Updated: 2019/11/29 17:20:32 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*aux;
	size_t	len;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	aux = malloc(count * size);
	if (!aux)
		return (NULL);
	len = count * size;
	while (len--)
	{
		*((unsigned char*)aux + len) = 0;
	}
	return (aux);
}

t_remain	*ft_lstnew(int fd)
{
	t_remain *aux;

	if (!(aux = (t_remain*)malloc(sizeof(*aux))))
		return (NULL);
	aux->fd = fd;
	aux->content = ft_calloc(1, sizeof(char));
	aux->next = NULL;
	return (aux);
}

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*aux;

	i = 0;
	while (*(s + i))
		++i;
	aux = (char*)s;
	while (i--)
	{
		if (*(aux++) == (unsigned char)c)
			return (--aux);
	}
	return (NULL);
}

char		*copy_line(char **s1)
{
	int		i;
	int		n;
	char	*aux;
	char	*new_content;

	i = 0;
	while (*(*s1 + i) != '\n')
		++i;
	if (!(aux = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	n = -1;
	while (++n < i)
		*(aux + n) = *(*s1 + n);
	i = 0;
	while (*(*s1 + n + i))
		++i;
	if (!(new_content = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	i = 0;
	while (*(*s1 + ++n))
		*(new_content + i++) = *(*s1 + n);
	free(*s1);
	*s1 = new_content;
	return (aux);
}

char		*ft_strjoin(char *s1, char const *s2)
{
	size_t	size;
	size_t	s1_size;
	size_t	i;
	char	*aux;

	s1_size = 0;
	while (*(s1 + s1_size) != '\0')
		++s1_size;
	size = 0;
	while (*(s2 + size))
		++size;
	size = size + s1_size;
	if (!(aux = ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	i = -1;
	while (++i < s1_size)
		*(aux + i) = *(s1 + i);
	i = 0;
	while ((s1_size + i) < size)
	{
		*(aux + i + s1_size) = *(s2 + i);
		++i;
	}
	free(s1);
	return (aux);
}
