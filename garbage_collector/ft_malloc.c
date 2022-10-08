/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:44:09 by apayet            #+#    #+#             */
/*   Updated: 2022/06/15 17:44:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_malloc(size_t size)
{
	void	*container;

	container = (void *)0;
	container = malloc(size);
	if (container == (void *)0)
	{
		set_error_state(MALLOC_ERROR);
		return ((void *)0);
	}
	if (get_garbage() == (t_list *)0)
		*get_garbage_addr() = ft_lstnew(container);
	else
		ft_lstadd_back(get_garbage_addr(), ft_lstnew(container));
	return (container);
}
