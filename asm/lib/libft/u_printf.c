/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:15:14 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 17:01:30 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_precision_u(char **res, t_mod *md)
{
	char	*tmp;
	char	*del;

	tmp = ft_strnew(md->preci - (int)ft_strlen(*res));
	tmp = ft_memset(tmp, '0', md->preci - (int)ft_strlen(*res));
	del = *res;
	*res = ft_strjoin(tmp, *res);
	ft_strdel(&tmp);
	ft_strdel(&del);
}

void	make_width_u(char **res, t_flags *fl, t_mod *md)
{
	char	*tmp;
	char	*del;

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
	ft_strdel(&tmp);
	ft_strdel(&del);
}

char	*take_u(va_list ap, t_mod *md)
{
	char			*res;

	if (md->h == 1)
		res = ft_itoa_u((unsigned short)va_arg(ap, unsigned int));
	else if (md->hh == 1)
		res = ft_itoa_u((unsigned char)va_arg(ap, unsigned int));
	else if (md->l == 1)
		res = ft_itoa_u(va_arg(ap, unsigned long int));
	else if (md->ll == 1)
		res = ft_itoa_u(va_arg(ap, unsigned long long int));
	else if (md->z == 1)
		res = ft_itoa_u(va_arg(ap, size_t));
	else if (md->j == 1)
		res = ft_itoa_u(va_arg(ap, intmax_t));
	else
		res = ft_itoa_u(va_arg(ap, unsigned int));
	return (res);
}

char	*u_printf(va_list ap, t_flags *fl, t_mod *md)
{
	char	*res;

	res = take_u(ap, md);
	if (md->preci == 0 && md->width == 0 &&
				res[0] == '0' && ft_strlen(res) == 1)
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
	if (md->preci > (int)ft_strlen(res))
		make_precision_u(&res, md);
	if (md->width > (int)ft_strlen(res))
		make_width_u(&res, fl, md);
	return (res);
}
