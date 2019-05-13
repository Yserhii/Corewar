/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:03:51 by yhliboch          #+#    #+#             */
/*   Updated: 2019/01/11 17:03:56 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*is_mod(char *fmt, t_mod **md)
{
	if (ft_strchr("hlLjz", *fmt) == NULL || *fmt == '\0')
		return (fmt);
	if (ft_strncmp("hh", fmt, 2) == 0)
	{
		(*md)->hh = 1;
		return (fmt += 2);
	}
	else if (ft_strncmp("h", fmt, 1) == 0)
		(*md)->h = 1;
	else if (ft_strncmp("ll", fmt, 2) == 0)
	{
		(*md)->ll = 1;
		return (fmt += 2);
	}
	else if (ft_strncmp("l", fmt, 1) == 0)
		(*md)->l = 1;
	else if (ft_strncmp("L", fmt, 1) == 0)
		(*md)->ld = 1;
	else if (ft_strncmp("j", fmt, 1) == 0)
		(*md)->j = 1;
	else if (ft_strncmp("z", fmt, 1) == 0)
		(*md)->z = 1;
	fmt += 1;
	return (fmt);
}

char	*is_preci(va_list ap, char *fmt, t_mod **md)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 0;
	if (*fmt != '.')
		return (fmt);
	fmt++;
	tmp = fmt;
	if (*fmt == '*')
	{
		i = va_arg(ap, int);
		i >= 0 ? (*md)->preci = i : 0;
		fmt++;
		return (fmt);
	}
	i = 0;
	while (ft_isdigit((int)tmp[i]) == 1)
		i++;
	res = ft_strnew(i);
	ft_strncpy(res, tmp, i);
	(*md)->preci = ft_atoi(res);
	fmt += ft_strlen(res);
	ft_strdel(&res);
	return (fmt);
}

char	*is_width(va_list ap, char *fmt, t_mod **md, t_flags **fl)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 0;
	tmp = fmt;
	if (ft_isdigit((int)tmp[i]) == 0 && *fmt != '*')
		return (fmt);
	if (*fmt == '*')
	{
		i = va_arg(ap, int);
		i < 0 ? (*fl)->hyp = 1 : 0;
		(*md)->width = ABS(i);
		fmt++;
		return (fmt);
	}
	i = 0;
	while (ft_isdigit((int)tmp[i]) == 1)
		i++;
	res = ft_strnew(i);
	ft_strncpy(res, tmp, i);
	(*md)->width = ft_atoi(res);
	fmt += ft_strlen(res);
	ft_strdel(&res);
	return (fmt);
}

char	*is_fl(char *fmt, t_flags **fl)
{
	int		i;
	char	*tmp;

	tmp = fmt;
	i = 0;
	if (ft_strchr("-+#0 ", *fmt) == NULL)
		return (fmt);
	while (ft_strchr("-+#0 ", *tmp) && *tmp)
	{
		*tmp == '-' ? (*fl)->hyp = 1 : 0;
		*tmp == '+' ? (*fl)->plus = 1 : 0;
		*tmp == '#' ? (*fl)->hesh = 1 : 0;
		*tmp == '0' ? (*fl)->zero = 1 : 0;
		*tmp == ' ' ? (*fl)->space = 1 : 0;
		tmp++;
		i++;
	}
	fmt += i;
	return (fmt);
}

char	*check(va_list ap, char *fmt, t_flags **fl, t_mod **md)
{
	char	*tmp;

	(*md)->preci = -1;
	while (ft_strchr("scpdiou%xXfUODI", *fmt) == NULL
						&& *fmt != '\0' && fmt != tmp)
	{
		tmp = fmt;
		fmt = is_fl(fmt, fl);
		fmt = is_width(ap, fmt, md, fl);
		fmt = is_preci(ap, fmt, md);
		fmt = is_mod(fmt, md);
	}
	if (*fmt == '\0')
	{
		free(*fl);
		free(*md);
	}
	return (fmt);
}
