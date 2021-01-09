/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loberyn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:25:51 by loberyn           #+#    #+#             */
/*   Updated: 2020/11/09 16:03:52 by loberyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&head, del);
			lst = NULL;
			return (NULL);
		}
		if (!head)
			head = new;
		else
			ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
