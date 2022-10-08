/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:39:15 by apayet            #+#    #+#             */
/*   Updated: 2021/12/06 09:39:16 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*elm;

	if (!lst)
		return (NULL);
	elm = ft_lstnew((void *)f(lst->content));
	if (!elm)
		return (NULL);
	lst = lst->next;
	head = elm;
	while (lst)
	{
		ft_lstadd_back(&elm, ft_lstnew((void *)f(lst->content)));
		if (!elm->content)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (head);
}
