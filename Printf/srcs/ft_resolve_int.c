/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:45:37 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/09 18:14:43 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put_part_int(char *n, int i, t_flags flags)
{
	int len;

	len = 0;
	if (i < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		len += ft_resolve_width(flags.dot - 1, ft_strlen(n) - 1, 1);
	len += ft_putnstr(n, ft_strlen(n));
	return (len);
}

static int	ft_put_int(char *n, int i, t_flags flags)
{
	int len;

	len = 0;
	if (flags.minus == 1)
		len += ft_put_part_int(n, i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(n))
		flags.dot = ft_strlen(n);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		len += ft_resolve_width(flags.width, 0, 0);
	}
	else
		len += ft_resolve_width(flags.width, ft_strlen(n), flags.zero);
	if (flags.minus == 0)
		len += ft_put_part_int(n, i, flags);
	return (len);
}

int			ft_resolve_int(int i, t_flags flags)
{
	char	*n;
	int		i_c;
	int		len;

	i_c = i;
	len = 0;
	if (flags.dot == 0 && i == 0)
	{
		len += ft_resolve_width(flags.width, 0, 0);
		return (len);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putnstr("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		len += 1;
	}
	n = ft_itoa(i);
	len += ft_put_int(n, i_c, flags);
	free(n);
	return (len);
}
