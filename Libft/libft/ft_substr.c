/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:53:59 by loberyn           #+#    #+#             */
/*   Updated: 2020/11/17 18:29:47 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			slen;
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		str = ft_calloc(1, sizeof(char));
	else
	{
		len = slen - start < len ? slen - start : len;
		if (!(str = (char *)malloc(len * sizeof(char) + 1)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			str[i] = s[start + i];
			i += 1;
		}
		str[i] = '\0';
	}
	return (str);
}
