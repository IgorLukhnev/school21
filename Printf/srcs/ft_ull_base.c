/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:38:35 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/09 17:39:54 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_resolve_base(unsigned long long ull, int base,
char *rtn, int count)
{
	while (ull != 0)
	{
		if ((ull % base) < 10)
			rtn[count - 1] = (ull % base) + 48;
		else
			rtn[count - 1] = (ull % base) + 55;
		ull /= base;
		count--;
	}
	return (rtn);
}

char		*ft_ull_base(unsigned long long ull, int base)
{
	char				*rtn;
	unsigned long long	ull_c;
	int					count;

	rtn = 0;
	count = 0;
	ull_c = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(rtn = malloc(sizeof(char) * (count + 1))))
		return (0);
	rtn[count] = '\0';
	rtn = ft_resolve_base(ull_c, base, rtn, count);
	return (rtn);
}
