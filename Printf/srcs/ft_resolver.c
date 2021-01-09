/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:27:49 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/09 17:31:32 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		ft_is_flag(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int		ft_resolver(int c, t_flags flags, va_list args)
{
	int len;

	len = 0;
	if (c == 'c')
		len += ft_resolve_ch(va_arg(args, int), flags);
	else if (c == 's')
		len += ft_resolve_str(va_arg(args, char *), flags);
	else if (c == 'p')
		len += ft_resolve_ptr(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		len += ft_resolve_int(va_arg(args, int), flags);
	else if (c == 'u')
		len += ft_resolve_uint((unsigned int)va_arg(args, unsigned int),
		flags);
	else if (c == 'x')
		len += ft_resolve_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		len += ft_resolve_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		len += ft_resolve_percent(flags);
	return (len);
}
