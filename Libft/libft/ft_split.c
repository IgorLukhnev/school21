/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:15:30 by loberyn           #+#    #+#             */
/*   Updated: 2020/11/17 15:11:34 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *s, char c)
{
	unsigned int	i;
	size_t			w;

	i = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] != c)
			w += 1;
		while (s[i] != c && s[i + 1])
			i += 1;
		i += 1;
	}
	return (w);
}

size_t	ft_wordlen(const char *s, char c)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i += 1;
	while (s[i] != c && s[i++])
		len += 1;
	return (len);
}

char	**ft_free(char **arr, size_t n)
{
	size_t	l;

	l = 0;
	while (l < n)
		free(arr[l++]);
	free(arr);
	arr = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**arr;
	size_t	words;

	i = 0;
	k = 0;
	words = s ? ft_wordcount(s, c) : 0;
	if (!s || !(arr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		if (!(arr[i] = (char *)malloc(sizeof(char) * ft_wordlen(&s[k], c) + 1)))
			return (ft_free(arr, i));
		j = 0;
		while (s[k] == c)
			k += 1;
		while (s[k] != c && s[k])
			arr[i][j++] = s[k++];
		arr[i][j] = '\0';
		i += 1;
	}
	arr[i] = NULL;
	return (arr);
}
