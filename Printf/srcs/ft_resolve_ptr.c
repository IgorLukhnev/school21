/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:04:35 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/09 18:15:27 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_put_ptr(char *ptr, t_flags flags)
{
	int len;

	len = 0;
	len += ft_putnstr("0x", 2);
	if (flags.dot >= 0)
	{
		len += ft_resolve_width(flags.dot, ft_strlen(ptr), 1);
		len += ft_putnstr(ptr, flags.dot);
	}
	else
		len += ft_putnstr(ptr, ft_strlen(ptr));
	return (len);
}

int			ft_resolve_ptr(unsigned long long ull, t_flags flags)
{
	char	*ptr;
	int		len;

	len = 0;
	if (ull == 0 && flags.dot == 0)
	{
		len += ft_putnstr("0x", 2);
		return (len += ft_resolve_width(flags.width, 0, 1));
	}
	ptr = ft_ull_base(ull, 16);
	ptr = ft_strtolower(ptr);
	if ((size_t)flags.dot < ft_strlen(ptr))
		flags.dot = ft_strlen(ptr);
	if (flags.minus == 1)
		len += ft_put_ptr(ptr, flags);
	len += ft_resolve_width(flags.width, ft_strlen(ptr) + 2, 0);
	if (flags.minus == 0)
		len += ft_put_ptr(ptr, flags);
	free(ptr);
	return (len);
}
