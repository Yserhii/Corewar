/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:54:53 by yhliboch          #+#    #+#             */
/*   Updated: 2019/02/08 17:01:11 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		make_flags_f(char **res, t_flags *fl, t_mod *md)
{
	char	*tmp;

	tmp = *res;
	if (md->sign > 0)
	{
		*res = ft_strjoin("-", *res);
		ft_strdel(&tmp);
	}
	else if (fl->plus > 0 && md->sign == 0)
	{
		*res = ft_strjoin("+", *res);
		ft_strdel(&tmp);
	}
	else if (fl->plus == 0 && fl->space > 0 && md->sign == 0)
	{
		*res = ft_strjoin(" ", *res);
		ft_strdel(&tmp);
	}
}

char		*inf(t_flags *fl, t_mod **md)
{
	char	*res;

	fl->zero = 0;
	(*md)->preci = 4;
	if ((*md)->sign == 1)
		res = ((*md)->l == 1 ? ft_strdup("-INF") : ft_strdup("-inf"));
	else if (fl->plus == 1)
		res = ((*md)->l == 1 ? ft_strdup("+INF") : ft_strdup("+inf"));
	else if (fl->plus == 0 && fl->space == 1)
		res = ((*md)->l == 1 ? ft_strdup(" INF") : ft_strdup(" inf"));
	else
		res = ((*md)->l == 1 ? ft_strdup("INF") : ft_strdup("inf"));
	make_width_s(&res, fl, *md);
	return (res);
}

double		ft_round(double n, t_mod *md)
{
	double	temp;
	int		i;

	if (md->preci != 0)
		temp = n - (long long)n;
	else
		temp = n;
	i = (md->preci == -1 ? 6 : md->preci);
	while (i-- > 0)
		temp *= 10;
	if ((long long)(temp + 0.5) % 2 == 0)
		temp += 0.5;
	else
		temp += 0.49;
	i = (md->preci == -1 ? 6 : md->preci);
	while (i-- > 0)
		temp /= 10;
	if (md->preci != 0)
		temp += (long long)n;
	return (temp);
}
