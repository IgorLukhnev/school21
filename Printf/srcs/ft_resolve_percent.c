/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:55:06 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/08 17:58:18 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_resolve_percent(t_flags flags)
{
	int len;

	len = ft_resolve_width(flags.width, 1, flags.zero);
	if (flags.minus == 1 || flags.minus == 0)
		len += ft_putnstr("%", 1);
	return (len);
}
