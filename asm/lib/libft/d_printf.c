/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:13:51 by yhliboch          #+#    #+#             */
/*   Updated: 2019/01/14 13:13:53 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_flags(char **res, t_flags *fl, t_mod *md)
{
	char	*tmp;

	if (md->sign > 0)
	{
		tmp = *res;
		*res = ft_strjoin("-", *res);
		ft_strdel(&tmp);
	}
	if (fl->plus > 0 && md->sign == 0)
	{
		tmp = *res;
		*res = ft_strjoin("+", *res);
		ft_strdel(&tmp);
	}
	if (fl->space > 0 && fl->plus == 0 && md->sign == 0)
	{
		tmp = *res;
		*res = ft_strjoin(" ", *res);
		ft_strdel(&tmp);
	}
}

void	make_precision(char **res, t_mod *md)
{
	char	*tmp;
	char	*temp;

	if (md->preci < (int)ft_strlen(*res))
		return ;
	tmp = ft_strnew(md->preci - (int)ft_strlen(*res));
	tmp = ft_memset(tmp, '0', md->preci - (int)ft_strlen(*res));
	temp = *res;
	*res = ft_strjoin(tmp, *res);
	ft_strdel(&tmp);
	ft_strdel(&temp);
}

void	make_width(char **res, t_flags *fl, t_mod *md)
{
	char	*tmp;
	char	*temp;

	if (md->width < (int)ft_strlen(*res))
		return ;
	tmp = ft_strnew(md->width - (int)ft_strlen(*res));
	if (fl->hyp == 0 && fl->zero == 1 && md->preci == -1)
	{
		if (md->sign > 0 || fl->plus > 0 || fl->space > 0)
			tmp = ft_memset(tmp, '0', md->width - (int)ft_strlen(*res) - 1);
		else
			tmp = ft_memset(tmp, '0', md->width - (int)ft_strlen(*res));
		temp = *res;
		*res = ft_strjoin(tmp, *res);
		ft_strdel(&temp);
		make_flags(res, fl, md);
	}
	else
	{
		tmp = ft_memset(tmp, ' ', md->width - (int)ft_strlen(*res));
		temp = *res;
		*res = (fl->hyp > 0 ? ft_strjoin(*res, tmp) : (ft_strjoin(tmp, *res)));
		ft_strdel(&temp);
	}
	ft_strdel(&tmp);
}

char	*take_d(va_list ap, t_mod **md)
{
	char	*res;

	if ((*md)->ll == 1)
		res = ft_itoa_d(va_arg(ap, long long int), md);
	else if ((*md)->l == 1)
		res = ft_itoa_d(va_arg(ap, long int), md);
	else if ((*md)->j == 1)
		res = ft_itoa_d(va_arg(ap, intmax_t), md);
	else if ((*md)->z == 1)
		res = ft_itoa_d(va_arg(ap, size_t), md);
	else if ((*md)->h == 1)
		res = ft_itoa_d((short)va_arg(ap, int), md);
	else if ((*md)->hh == 1)
		res = ft_itoa_d((char)va_arg(ap, int), md);
	else
		res = ft_itoa_d(va_arg(ap, int), md);
	return (res);
}

char	*d_printf(va_list ap, t_flags *fl, t_mod **md)
{
	char	*res;

	res = take_d(ap, md);
	if ((*md)->preci == 0 && res[0] == '0' && ft_strlen(res) == 1)
	{
		ft_strdel(&res);
		if ((*md)->width == 0)
		{
			if (fl->space == 0 && fl->plus == 0)
				return (NULL);
			res = ft_strnew(0);
			make_flags(&res, fl, *md);
			return (res);
		}
		else
			res = ft_strnew((*md)->width);
	}
	make_precision(&res, *md);
	if (fl->zero == 0 || (*md)->width < (int)ft_strlen(res)
						|| fl->hyp == 1 || (*md)->preci > -1)
		make_flags(&res, fl, *md);
	make_width(&res, fl, *md);
	return (res);
}
