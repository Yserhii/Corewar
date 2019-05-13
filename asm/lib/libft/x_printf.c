/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:14:27 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 17:01:33 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_hesh(char **res, t_mod *md, t_flags *fl)
{
	char	*tmp;

	if (fl->hesh != 1)
		return ;
	tmp = *res;
	if (md->x == 1)
		*res = ft_strjoin("0X", *res);
	else
		*res = ft_strjoin("0x", *res);
	ft_strdel(&tmp);
}

void	make_precision_x(char **res, t_mod *md, t_flags *fl)
{
	char	*tmp;
	char	*del;

	if (md->preci > (int)ft_strlen(*res))
	{
		tmp = ft_strnew(md->preci - (int)ft_strlen(*res));
		tmp = ft_memset(tmp, '0', md->preci - (int)ft_strlen(*res));
		del = *res;
		*res = ft_strjoin(tmp, *res);
		ft_strdel(&del);
		ft_strdel(&tmp);
	}
	if (fl->zero != 1 || (fl->hyp == 1 && fl->zero == 1) ||
				(fl->zero == 1 && md->preci != -1) || md->width == 0)
		make_hesh(res, md, fl);
}

void	make_width_x(char **res, t_flags *fl, t_mod *md)
{
	char	*tmp;
	char	*del;

	del = *res;
	if (fl->hyp == 0 && fl->zero == 1 && md->preci == -1)
	{
		tmp = (fl->hesh == 1 ? ft_strnew(md->width - ft_strlen(*res) - 2)
				: ft_strnew(md->width - ft_strlen(*res)));
		if (fl->hesh == 1)
			tmp = ft_memset(tmp, '0', md->width - ft_strlen(*res) - 2);
		else
			tmp = ft_memset(tmp, '0', md->width - ft_strlen(*res));
		*res = ft_strjoin(tmp, *res);
		if (fl->hesh == 1)
			make_hesh(res, md, fl);
	}
	else
	{
		tmp = ft_strnew(md->width - ft_strlen(*res));
		tmp = ft_memset(tmp, ' ', md->width - ft_strlen(*res));
		*res = (fl->hyp > 0 ? ft_strjoin(*res, tmp) : (ft_strjoin(tmp, *res)));
	}
	ft_strdel(&del);
	ft_strdel(&tmp);
}

char	*take_x(va_list ap, t_mod *md)
{
	char	*res;

	if (md->h == 1)
		res = ft_itoa_x((unsigned short)va_arg(ap, unsigned int), md);
	else if (md->hh == 1)
		res = ft_itoa_x((unsigned char)va_arg(ap, unsigned int), md);
	else if (md->l == 1)
		res = ft_itoa_x(va_arg(ap, unsigned long int), md);
	else if (md->ll == 1)
		res = ft_itoa_x(va_arg(ap, unsigned long long int), md);
	else if (md->z == 1)
		res = ft_itoa_x(va_arg(ap, size_t), md);
	else if (md->j == 1)
		res = ft_itoa_x(va_arg(ap, intmax_t), md);
	else
		res = ft_itoa_x(va_arg(ap, unsigned int), md);
	return (res);
}

char	*x_printf(va_list ap, t_flags *fl, t_mod *md)
{
	char	*res;

	res = take_x(ap, md);
	if (md->preci == 0 && res[0] == '0' && ft_strlen(res) == 1)
	{
		ft_strdel(&res);
		if (md->width == 0)
			return (NULL);
		res = ft_strnew(md->width);
	}
	else if (md->preci != 0 && res[0] == '0' && ft_strlen(res) == 1)
		fl->hesh = 0;
	make_precision_x(&res, md, fl);
	if (md->width > (int)ft_strlen(res))
		make_width_x(&res, fl, md);
	return (res);
}
