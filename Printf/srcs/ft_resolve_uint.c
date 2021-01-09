/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:20:49 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/09 18:16:58 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put_part_uint(char *uint, t_flags flags)
{
	int len;

	len = 0;
	if (flags.dot >= 0)
		len += ft_resolve_width(flags.dot - 1, ft_strlen(uint) - 1, 1);
	len += ft_putnstr(uint, ft_strlen(uint));
	return (len);
}

static int	ft_put_uint(char *uint, t_flags flags)
{
	int len;

	len = 0;
	if (flags.minus == 1)
		len += ft_put_part_uint(uint, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(uint))
		flags.dot = ft_strlen(uint);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		len += ft_resolve_width(flags.width, 0, 0);
	}
	else
		len += ft_resolve_width(flags.width,
		ft_strlen(uint), flags.zero);
	if (flags.minus == 0)
		len += ft_put_part_uint(uint, flags);
	return (len);
}

int			ft_resolve_uint(unsigned int ui, t_flags flags)
{
	char	*uint;
	int		len;

	len = 0;
	ui = (unsigned int)(4294967295 + 1
				+ ui);
	if (flags.dot == 0 && ui == 0)
	{
		len += ft_resolve_width(flags.width, 0, 0);
		return (len);
	}
	uint = ft_uitoa(ui);
	len += ft_put_uint(uint, flags);
	free(uint);
	return (len);
}
