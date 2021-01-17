/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:45:37 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/17 16:21:49 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_resolve_sign(int i, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.minus == 1)
		flags.width *= -1;
	if (flags.dot == 0 && i == 0 && flags.width > 0)
		len += ft_resolve_width(flags.width, flags.space || flags.plus, 0);
	if (i >= 0)
	{
		if (flags.space == 1)
			len += ft_putchar(' ');
		else if (flags.plus == 1)
			len += ft_putchar('+');
	}
	if (flags.dot == 0 && i == 0 && flags.width <= 0)
		len += ft_resolve_width(-1 * flags.width, flags.space || flags.plus, 0);
	return (len);
}

static int	ft_put_part_int(char *n, int i, t_flags flags)
{
	int len;
	int offset;

	len = 0;
	if (i < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.zero == 0)
		len += ft_resolve_sign(i, flags);
	offset = (int)(i < 0 || len);
	if (flags.dot >= 0)
		len += ft_resolve_width(flags.dot - offset, ft_strlen(n) - offset, 1);
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
		len += ft_resolve_width(flags.width,
				(i >= 0) * (flags.plus || flags.space), 0);
		if (flags.zero == 1)
			len += ft_resolve_sign(i, flags);
	}
	else
	{
		len += (flags.zero == 1) ? ft_resolve_sign(i, flags) : 0;
		len += ft_resolve_width(flags.width,
				ft_strlen(n) + (i >= 0) * (flags.plus || flags.space),
				flags.zero);
	}
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
		return (len += ft_resolve_sign(i, flags));
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
