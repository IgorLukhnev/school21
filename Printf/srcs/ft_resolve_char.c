/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:39:09 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/17 12:27:03 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_resolve_ch(char c, t_flags flags)
{
	int len;

	len = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	len = ft_resolve_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (len + 1);
}
