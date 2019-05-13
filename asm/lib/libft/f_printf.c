/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:05:24 by yhliboch          #+#    #+#             */
/*   Updated: 2019/01/21 13:05:26 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		make_preci(t_mod **md, double f, char **res)
{
	char		*res1;
	char		*temp;
	char		*tmp;
	int			i;

	f = f - (long long)f;
	if ((*md)->preci == -1)
		(*md)->preci = 6;
	i = (*md)->preci;
	while (i-- > 0)
		f *= 10;
	res1 = ft_itoa_f(f);
	if ((*md)->preci > (int)ft_strlen(res1))
	{
		temp = ft_strnew((*md)->preci - (int)ft_strlen(res1));
		temp = ft_memset(temp, '0', (*md)->preci - (int)ft_strlen(res1));
		tmp = res1;
		res1 = ft_strjoin(res1, temp);
		ft_strdel(&tmp);
		ft_strdel(&temp);
	}
	tmp = *res;
	*res = ft_strjoin(*res, res1);
	ft_strdel(&tmp);
	ft_strdel(&res1);
}

void		make_width_f(char **res, t_flags *fl, t_mod *md)
{
	char	*tmp;
	char	*del;

	if (md->width <= (int)ft_strlen(*res) || fl->zero == 0 || fl->hyp == 1)
		make_flags_f(res, fl, md);
	if (md->width <= (int)ft_strlen(*res))
		return ;
	tmp = ft_strnew(md->width - (int)ft_strlen(*res));
	del = *res;
	if (fl->hyp == 0 && fl->zero == 1)
	{
		if (md->sign > 0 || fl->plus > 0 || fl->space > 0)
			tmp = ft_memset(tmp, '0', md->width - (int)ft_strlen(*res) - 1);
		else
			tmp = ft_memset(tmp, '0', md->width - (int)ft_strlen(*res));
		*res = ft_strjoin(tmp, *res);
		make_flags_f(res, fl, md);
	}
	else
	{
		tmp = ft_memset(tmp, ' ', md->width - (int)ft_strlen(*res));
		*res = (fl->hyp > 0 ? ft_strjoin(*res, tmp) : (ft_strjoin(tmp, *res)));
	}
	ft_strdel(&del);
	ft_strdel(&tmp);
}

char		*check_f(double f, t_flags *fl, t_mod **md)
{
	char	*res;

	if (f != f)
	{
		(*md)->preci = 3;
		fl->zero = 0;
		res = ((*md)->l == 1 ? ft_strdup("NAN") : ft_strdup("nan"));
		make_width_s(&res, fl, *md);
	}
	else if ((f * 2) == f && f != 0)
	{
		res = inf(fl, md);
	}
	else
		return (NULL);
	return (res);
}

double		take_f(va_list ap, t_mod **md)
{
	double		f;
	__uint64_t	*b;

	if ((*md)->ld == 1)
		f = va_arg(ap, long double);
	else
		f = (va_arg(ap, double));
	b = (__uint64_t *)&f;
	(*md)->sign = (*b >> 63 == 1 ? 1 : 0);
	f = ABS(f);
	return (f);
}

char		*f_printf(va_list ap, t_flags *fl, t_mod **md)
{
	double	f;
	char	*res;
	char	*tmp;

	f = take_f(ap, md);
	if ((res = check_f(f, fl, md)) != NULL)
		return (res);
	f = ft_round(f, *md);
	res = ft_itoa_f(f);
	if ((*md)->preci != 0)
	{
		tmp = res;
		res = ft_strjoin(res, ".");
		ft_strdel(&tmp);
		make_preci(md, f, &res);
	}
	else if (fl->hesh == 1 && (*md)->preci == 0)
	{
		tmp = res;
		res = ft_strjoin(res, ".");
		ft_strdel(&tmp);
	}
	make_width_f(&res, fl, *md);
	return (res);
}
