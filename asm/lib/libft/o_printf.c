/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:13:32 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 17:01:00 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_precision_o(char **res, t_mod *md, t_flags *fl)
{
	char	*tmp;
	char	*del;

	del = *res;
	if (md->preci > (int)ft_strlen(*res))
	{
		tmp = ft_strnew(md->preci - (int)ft_strlen(*res));
		tmp = ft_memset(tmp, '0', md->preci - (int)ft_strlen(*res));
		*res = ft_strjoin(tmp, *res);
		ft_strdel(&tmp);
		ft_strdel(&del);
	}
	else if (md->preci <= (int)ft_strlen(*res) && fl->hesh == 1)
	{
		*res = ft_strjoin("0", *res);
		ft_strdel(&del);
	}
}

void	make_width_o(char **res, t_flags *fl, t_mod *md)
{
	char	*tmp;
	char	*del;

	if (md->width < (int)ft_strlen(*res))
		return ;
	del = *res;
	tmp = ft_strnew(md->width - (int)ft_strlen(*res));
	if (fl->hyp == 0 && fl->zero == 1 && md->preci == -1)
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

char	*take_o(va_list ap, t_mod *md)
{
	char			*res;

	if (md->h == 1)
		res = ft_itoa_base((unsigned short)va_arg(ap, unsigned int), 8);
	else if (md->hh == 1)
		res = ft_itoa_base((unsigned char)va_arg(ap, unsigned int), 8);
	else if (md->l == 1)
		res = ft_itoa_base(va_arg(ap, unsigned long int), 8);
	else if (md->ll == 1)
		res = ft_itoa_base(va_arg(ap, unsigned long long int), 8);
	else if (md->z == 1)
		res = ft_itoa_base(va_arg(ap, size_t), 8);
	else if (md->j == 1)
		res = ft_itoa_base(va_arg(ap, intmax_t), 8);
	else
		res = ft_itoa_base(va_arg(ap, unsigned int), 8);
	return (res);
}

char	*o_printf(va_list ap, t_flags *fl, t_mod *md)
{
	char	*res;

	res = take_o(ap, md);
	if (md->preci == 0 && md->width == 0 &&
				res[0] == '0' && ft_strlen(res) == 1 && fl->hesh == 0)
	{
		ft_strdel(&res);
		return (NULL);
	}
	else if (md->preci == 0 && md->width != 0 &&
				res[0] == '0' && ft_strlen(res) == 1)
	{
		ft_strdel(&res);
		res = ft_strnew(md->width);
	}
	else if ((md->preci == -1 || md->preci == 0) && res[0] == '0' &&
				ft_strlen(res) == 1 && fl->hesh == 1)
		fl->hesh = 0;
	make_precision_o(&res, md, fl);
	make_width_o(&res, fl, md);
	return (res);
}
