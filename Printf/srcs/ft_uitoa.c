/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:32:20 by loberyn           #+#    #+#             */
/*   Updated: 2021/01/09 17:37:56 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_llen(long n)
{
	size_t	llen;

	llen = 0;
	if (n < 0)
	{
		llen++;
		n = -n;
	}
	while (n >= 1)
	{
		llen++;
		n /= 10;
	}
	return (llen);
}

static char	*ft_gen(char *rtn, long nbr, int len, int isneg)
{
	if (nbr != 0)
		rtn = malloc(sizeof(char) * (len + 1));
	else
		return (rtn = ft_strdup("0"));
	if (!rtn)
		return (0);
	isneg = 0;
	if (nbr < 0)
	{
		rtn[0] = '-';
		nbr = -nbr;
	}
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (rtn[0] != '-')
		rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char		*ft_u_itoa(unsigned int n)
{
	int		len;
	char	*rtn;
	long	nbr;
	int		isneg;

	nbr = n;
	len = ft_llen(nbr);
	rtn = 0;
	isneg = 0;
	if (!(rtn = ft_gen(rtn, nbr, len, isneg)))
		return (0);
	return (rtn);
}
