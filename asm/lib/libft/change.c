/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:07:53 by yhliboch          #+#    #+#             */
/*   Updated: 2019/01/21 11:07:55 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_new_fmt(t_list **list, char *res)
{
	t_list	*new;

	new = ft_lstnew((void const *)res, ft_strlen(res));
	if (*list == NULL)
		*list = new;
	else
		ft_lstaddend(list, new);
}

char	*change2(char *fmt, va_list ap, t_flags *fl, t_mod **md)
{
	(*md)->l = 1;
	(*md)->h = 0;
	(*md)->hh = 0;
	(*md)->ll = 0;
	if (*fmt == 'U')
		return (u_printf(ap, fl, *md));
	if (*fmt == 'O')
		return (o_printf(ap, fl, *md));
	if (*fmt == 'D' || *fmt == 'I')
		return (d_printf(ap, fl, md));
	if (*fmt == 'F')
		return (f_printf(ap, fl, md));
	else
		return (NULL);
}

char	*change(char *fmt, va_list ap, t_flags *fl, t_mod **md)
{
	if (*fmt == 'd' || *fmt == 'i')
		return (d_printf(ap, fl, md));
	if (*fmt == 'u')
		return (u_printf(ap, fl, *md));
	if (*fmt == 'o')
		return (o_printf(ap, fl, *md));
	if (*fmt == 'X' || *fmt == 'x')
	{
		*fmt == 'X' ? (*md)->x = 1 : 0;
		return (x_printf(ap, fl, *md));
	}
	if (*fmt == 'p')
		return (p_printf(ap, fl, *md));
	if (*fmt == 's')
		return (s_printf(ap, fl, *md));
	if (*fmt == 'c')
		return (c_printf(ap, fl, *md, fmt));
	if (*fmt == '%')
		return (percent(fl, *md));
	if (*fmt == 'f')
		return (f_printf(ap, fl, md));
	else
		return (change2(fmt, ap, fl, md));
}

char	*check_change(char *fmt, va_list ap, t_list **list)
{
	t_flags	*fl;
	t_mod	*md;
	char	*res;

	fl = ft_memalloc(sizeof(t_flags));
	md = ft_memalloc(sizeof(t_mod));
	fmt++;
	fmt = check(ap, fmt, &fl, &md);
	if (ft_strchr("scpdiou%xXfUODIF", *fmt) == NULL || *fmt == '\0')
	{
		if (*fmt == '\0')
			return (fmt);
		fl->nul = 1;
		res = c_printf(ap, fl, md, fmt);
	}
	else
		res = change(fmt, ap, fl, &md);
	if (res != NULL)
	{
		make_new_fmt(list, res);
		ft_strdel(&res);
	}
	free(fl);
	free(md);
	return (fmt + 1);
}
