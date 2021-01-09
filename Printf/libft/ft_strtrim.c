/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:51:35 by loberyn           #+#    #+#             */
/*   Updated: 2020/11/02 15:59:16 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ischarin(char c, char const *set)
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	unsigned int	start;

	if (!s1)
		return (NULL);
	start = 0;
	len = ft_strlen(s1) - 1;
	while (s1[start])
	{
		if (ft_ischarin(s1[start], set))
			start++;
		else
			break ;
	}
	while (s1[len])
	{
		if (ft_ischarin(s1[len], set))
			len--;
		else
			break ;
	}
	return (ft_substr(s1, start, len - start + 1));
}
