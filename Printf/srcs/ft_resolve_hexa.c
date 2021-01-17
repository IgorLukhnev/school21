/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:27:13 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/17 14:32:13 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_minus_hexa(char *input, t_flags flags, int lower)
{
	int	len;

	len = 0;
	if (flags.hash == 1)
		len += lower == 1 ? ft_putnstr("0x", 2) : ft_putnstr("0X", 2);
	if (flags.hash == 1 && flags.zero == 1)
		len += ft_resolve_width(flags.width, ft_strlen(input) + 2 * flags.hash,
				flags.zero);
	if (flags.dot >= 0)
		len += ft_resolve_width(flags.dot - 1 - len, ft_strlen(input) - 1 - len,
				1);
	len += ft_putnstr(input, ft_strlen(input));
	return (len);
}

static int	ft_zero_hexa(char *input, t_flags flags, int lower)
{
	int	len;

	len = 0;
	if (flags.minus == 1)
		len += ft_minus_hexa(input, flags, lower);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(input))
		flags.dot = ft_strlen(input);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		len += ft_resolve_width(flags.width, flags.hash * 2, 0);
	}
	else if (flags.hash != 1 || flags.zero != 1)
		len += ft_resolve_width(flags.width, ft_strlen(input) + 2 * flags.hash,
				flags.zero);
	if (flags.minus == 0)
		len += ft_minus_hexa(input, flags, lower);
	return (len);
}

int			ft_resolve_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*input;
	int		len;

	len = 0;
	flags.hash = ui == 0 ? 0 : flags.hash;
	ui = (unsigned int)(4294967295 + 1 + ui);
	if (flags.dot == 0 && ui == 0)
	{
		len += ft_resolve_width(flags.width, 0, 0);
		return (len);
	}
	input = ft_ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		input = ft_strtolower(input);
	len += ft_zero_hexa(input, flags, lower);
	free(input);
	return (len);
}
