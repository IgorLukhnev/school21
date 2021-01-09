/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:29:38 by loberyn           #+#    #+#             */
/*   Updated: 2020/10/29 17:32:01 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	int		j;

	len = ft_strlen(s);
	j = 0;
	while (len >= j)
		if (s[len - j++] == c)
			return ((char *)&s[len - (j - 1)]);
	return (NULL);
}
