/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:36:52 by loberyn           #+#    #+#             */
/*   Updated: 2020/11/02 15:58:29 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && (i < len))
	{
		while ((haystack[i + j] == needle[j] && needle[j] && ((i + j) < len)))
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		j = 0;
		i += 1;
	}
	return (NULL);
}
