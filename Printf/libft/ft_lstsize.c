/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:02:39 by loberyn           #+#    #+#             */
/*   Updated: 2020/11/09 12:05:38 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*to_go;

	len = 0;
	to_go = lst;
	while (to_go)
	{
		len += 1;
		to_go = to_go->next;
	}
	return (len);
}
