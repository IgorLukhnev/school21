/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:56:58 by loberyn           #+#    #+#             */
/*   Updated: 2020/11/09 22:47:57 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i])
	{
		s1[len + i] = s2[i];
		i += 1;
	}
	s1[len + i] = '\0';
	return (s1);
}

char	*ft_strcpy(char *str, char const *s, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*str;

	str = NULL;
	if (s1 && s2)
	{
		size1 = ft_strlen(s1);
		size2 = ft_strlen(s2);
		if (!(str = (char *)malloc(sizeof(char) * (size1 + size2) + 1)))
			return (NULL);
		ft_strcpy(str, s1, size1);
		ft_strcat(str, s2);
	}
	return (str);
}
