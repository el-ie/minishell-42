/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:39:40 by apayet            #+#    #+#             */
/*   Updated: 2022/07/08 12:30:09 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	if (content == (void *)0)
		return ((t_list *)0);
	new_node = (t_list *)0;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ((t_list *)0);
	new_node->content = content;
	new_node->next = (t_list *)0;
	return (new_node);
}
