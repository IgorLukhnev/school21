/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:48:37 by loberyn           #+#    #+#             */
/*   Updated: 2020/10/29 16:52:29 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t			len;
	unsigned char	*str;

	len = 0;
	str = (unsigned char *)s;
	while (str[len])
		len++;
	return (len);
}
