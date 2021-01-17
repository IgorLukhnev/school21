/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:16:57 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/17 12:11:44 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_put_str(char *str, t_flags flags)
{
	int len;

	len = 0;
	if (flags.dot >= 0)
	{
		len += ft_resolve_width(flags.dot, ft_strlen(str), 0);
		len += ft_putnstr(str, flags.dot);
	}
	else
	{
		len += ft_putnstr(str, ft_strlen(str));
	}
	return (len);
}

int				ft_resolve_str(char *str, t_flags flags)
{
	int len;

	len = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		len += ft_put_str(str, flags);
	if (flags.dot >= 0)
		len += ft_resolve_width(flags.width, flags.dot, 0);
	else
		len += ft_resolve_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		len += ft_put_str(str, flags);
	return (len);
}
