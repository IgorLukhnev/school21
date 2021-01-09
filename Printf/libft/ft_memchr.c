/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:34:01 by loberyn           #+#    #+#             */
/*   Updated: 2020/10/29 16:40:35 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char *ss;
	unsigned char		ch;

	i = 0;
	ss = (unsigned const char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (ss[i] == ch)
			return ((void *)&ss[i]);
		i++;
	}
	return (NULL);
}
