/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:55:06 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/17 12:02:21 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_resolve_percent(t_flags flags)
{
	int len;

	len = 0;
	if (flags.minus == 1)
		len += ft_putchar('%');
	len += ft_resolve_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		len += ft_putchar('%');
	return (len);
}
