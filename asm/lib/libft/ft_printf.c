/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 13:30:11 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 16:58:55 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print(t_list **list)
{
	t_list	*temp;
	int		res;
	char	*tmp;
	int		i;

	res = 0;
	while (*list != NULL)
	{
		i = 0;
		res += (int)ft_strlen((*list)->content);
		tmp = (*list)->content;
		while (tmp[i])
		{
			if (tmp[i] == -42)
				write(1, "\0", 1);
			else
				write(1, &tmp[i], 1);
			i++;
		}
		temp = *list;
		*list = (*list)->next;
		ft_strdel(&tmp);
		free(temp);
	}
	return (res);
}

char	*no_change(char *fmt, t_list **list)
{
	char	*res;

	if (ft_strchr(fmt, '%') != NULL)
	{
		res = ft_strnew(ft_strchr(fmt, '%') - fmt);
		res = ft_strncpy(res, fmt, (ft_strchr(fmt, '%') - fmt));
		make_new_fmt(list, res);
		fmt += ft_strlen(res);
	}
	else
	{
		res = ft_strnew(ft_strchr(fmt, '\0') - fmt);
		res = ft_strncpy(res, fmt, (ft_strchr(fmt, '\0') - fmt));
		make_new_fmt(list, res);
		fmt += ft_strlen(res);
	}
	ft_strdel(&res);
	return (fmt);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	char			*fmt;
	static t_list	*list;

	va_start(ap, format);
	fmt = (char *)format;
	while (*fmt)
	{
		if (*fmt == '%')
			fmt = check_change(fmt, ap, &list);
		else if (*fmt != '%' && *fmt)
			fmt = no_change(fmt, &list);
	}
	va_end(ap);
	return (ft_print(&list));
}
