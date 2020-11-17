/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:16:59 by loberyn           #+#    #+#             */
/*   Updated: 2020/11/09 17:35:32 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_iter;
	t_list	*next;

	if (!del || !lst || !*lst)
		return ;
	to_iter = *lst;
	while (to_iter && lst)
	{
		next = to_iter->next;
		ft_lstdelone(to_iter, del);
		to_iter = next;
	}
	*lst = NULL;
}
