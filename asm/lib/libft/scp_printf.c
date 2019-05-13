/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scp_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:07:40 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 17:01:26 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_width_s(char **res, t_flags *fl, t_mod *md)
{
	char	*tmp;
	char	*del;

	if (md->width < (int)ft_strlen(*res))
		return ;
	tmp = ft_strnew(md->width - (int)ft_strlen(*res));
	del = *res;
	if (fl->hyp == 0 && fl->zero == 1)
	{
		tmp = ft_memset(tmp, '0', md->width - (int)ft_strlen(*res));
		*res = ft_strjoin(tmp, *res);
	}
	else
	{
		tmp = ft_memset(tmp, ' ', md->width - (int)ft_strlen(*res));
		*res = (fl->hyp > 0 ? ft_strjoin(*res, tmp) : (ft_strjoin(tmp, *res)));
	}
	ft_strdel(&del);
	ft_strdel(&tmp);
}

char	*s_printf(va_list ap, t_flags *fl, t_mod *md)
{
	char	*res;
	char	*tmp;
	char	*del;

	tmp = va_arg(ap, char *);
	if (tmp == NULL)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(tmp);
	if (md->preci < (int)ft_strlen(res) && md->preci != -1)
	{
		tmp = ft_strnew(md->preci);
		tmp = ft_strncpy(tmp, res, md->preci);
		del = res;
		res = ft_strdup(tmp);
		ft_strdel(&tmp);
		ft_strdel(&del);
	}
	make_width_s(&res, fl, md);
	return (res);
}

char	*c_printf(va_list ap, t_flags *fl, t_mod *md, char *fmt)
{
	char	*res;
	char	c;

	if (fl->nul == 1)
		c = *fmt;
	else
	{
		c = va_arg(ap, int);
		if (c == 0)
			c = -42;
	}
	res = ft_strnew(1);
	res = ft_memset(res, c, 1);
	if (md->width > (int)ft_strlen(res))
		make_width_s(&res, fl, md);
	return (res);
}

char	*percent(t_flags *fl, t_mod *md)
{
	char	*res;

	res = ft_strnew(1);
	res = ft_memset(res, '%', 1);
	if (md->width > (int)ft_strlen(res))
		make_width_s(&res, fl, md);
	return (res);
}
