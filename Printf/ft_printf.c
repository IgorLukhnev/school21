/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:02:28 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/26 22:10:55 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	flags.hash = 0;
	flags.plus = 0;
	flags.space = 0;
	return (flags);
}

t_flags	*ft_bonus_flags(const char *str, int i, t_flags *flags)
{
	if (str[i] == '#')
		flags->hash = 1;
	if (str[i] == ' ')
		flags->space = 1;
	if (str[i] == '+')
	{
		flags->space = 0;
		flags->plus = 1;
	}
	return (flags);
}

int		ft_flag_parse(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_is_type(str[i])
				&& !ft_is_flag(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_dot_flag(str, i, flags, args);
		if (str[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (str[i] == '*')
			*flags = ft_flag_width(args, *flags);
		flags = ft_bonus_flags(str, i, flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flag_digit(str[i], *flags);
		if (ft_is_type(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		ft_resolve_input(const char *input, va_list args)
{
	int		i;
	t_flags	flags;
	int		len;

	i = 0;
	len = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!input[i])
			break ;
		else if (input[i] == '%' && input[i + 1])
		{
			i = ft_flag_parse(input, ++i, &flags, args);
			if (ft_is_type(input[i]))
				len += ft_resolver((char)flags.type, flags, args);
			else if (input[i])
				len += ft_putchar(input[i]);
		}
		else if (input[i] != '%')
			len += ft_putchar(input[i]);
		i++;
	}
	return (len);
}

int		ft_printf(const char *str, ...)
{
	const char	*input;
	va_list		args;
	int			len;

	input = ft_strdup(str);
	len = 0;
	va_start(args, str);
	len += ft_resolve_input(input, args);
	va_end(args);
	free((char *)input);
	return (len);
}
