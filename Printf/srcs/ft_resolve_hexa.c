/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:27:13 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/09 18:14:17 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_plus_hexa(char *input, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.dot >= 0)
		len += ft_resolve_width(flags.dot - 1, ft_strlen(input) - 1, 1);
	len += ft_putnstr(input, ft_strlen(input));
	return (len);
}

static int	ft_minus_hexa(char *input, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.minus == 1)
		len += ft_plus_hexa(input, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(input))
		flags.dot = ft_strlen(input);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		len += ft_resolve_width(flags.width, 0, 0);
	}
	else
		len += ft_resolve_width(flags.width, ft_strlen(input), flags.zero);
	if (flags.minus == 0)
		len += ft_plus_hexa(input, flags);
	return (len);
}

int			ft_resolve_hexa(unsigned int ui, int lower, t_flags flags)
{
	char	*input;
	int		len;

	len = 0;
	ui = (unsigned int)(4294967295 + 1 + ui);
	if (flags.dot == 0 && ui == 0)
	{
		len += ft_resolve_width(flags.width, 0, 0);
		return (len);
	}
	input = ft_ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		input = ft_strtolower(input);
	len += ft_minus_hexa(input, flags);
	free(input);
	return (len);
}
