/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserhii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:34:52 by yserhii           #+#    #+#             */
/*   Updated: 2018/12/11 14:25:22 by yserhii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_checkfd(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(list, tmp);
	return (tmp);
}

static void		check_new_line(t_list *list, char **buf)
{
	int	s;

	s = ft_strlen((char *)list->content);
	if (((char *)list->content)[s - 1] == '\n')
		g_new_line = 1;
	free(*buf);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*head;
	char			*buf;
	int				i;
	char			*tmp;

	buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (BUFF_SIZE <= 0 || fd < 0 || read(fd, buf, 0) < 0 || buf == 0)
		return (-1);
	head = list;
	list = ft_checkfd(&head, fd);
	while (!(ft_strchr(list->content, '\n')) && (i = read(fd, buf, BUFF_SIZE)))
		list->content = ft_strnjoin(list->content, buf, i);
	check_new_line(list, &buf);
	i = 0;
	while (((char *)list->content)[i] && ((char *)list->content)[i] != '\n')
		++i;
	*line = ft_strndup(list->content, i);
	if (((char *)list->content)[i] == '\n')
		++i;
	tmp = list->content;
	list->content = ft_strdup(&((char *)(list->content))[i]);
	free(tmp);
	list = head;
	return (i == 0 ? 0 : 1);
}
