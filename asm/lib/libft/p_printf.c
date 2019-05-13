/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:23:31 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 17:01:06 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_width_p(char **res, t_flags *fl, t_mod *md)
{
	char	*tmp;
	char	*del;

	if (md->width < (int)ft_strlen(*res))
		return ;
	del = *res;
	tmp = ft_strnew(md->width - (int)ft_strlen(*res));
	if (fl->hyp == 0 && fl->zero == 1 && (md->preci == -1 || md->preci == 0))
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

void	make_preci_p(char **res, t_mod *md)
{
	char	*temp;
	char	*tmp;

	if (md->preci > (int)ft_strlen(*res))
	{
		temp = ft_strnew(md->preci - (int)ft_strlen(*res));
		temp = ft_memset(temp, '0', md->preci - (int)ft_strlen(*res));
		tmp = *res;
		*res = ft_strjoin(temp, *res);
		ft_strdel(&tmp);
		ft_strdel(&temp);
	}
}

char	*p_printf(va_list ap, t_flags *fl, t_mod *md)
{
	char		*tmp;
	char		*res;

	res = ft_itoa_x(va_arg(ap, long int), md);
	if (res[0] == '0' && ft_strlen(res) == 1 && md->preci == 0)
	{
		fl->zero = 0;
		tmp = res;
		res = ft_strdup("0x");
		ft_strdel(&tmp);
		make_width_p(&res, fl, md);
		return (res);
	}
	if (md->width > (int)ft_strlen(res) && fl->zero == 1)
	{
		md->width -= 2;
		make_width_p(&res, fl, md);
	}
	make_preci_p(&res, md);
	tmp = res;
	res = ft_strjoin("0x", res);
	ft_strdel(&tmp);
	if (fl->zero == 0)
		make_width_p(&res, fl, md);
	return (res);
}
