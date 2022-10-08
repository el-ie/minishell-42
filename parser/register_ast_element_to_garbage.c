/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_ast_element_to_garbage.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:44:41 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 13:40:18 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Maybe change teh name of this function
 * 
 * @param ast_node 
 * @param need_reset 
 */
void	register_ast_element_to_garbage(void *any_elem, int need_reset)
{
	static t_list	*local_garbage = (t_list *)0;

	if (need_reset == TRUE)
	{
		ft_lstclear(&(local_garbage), &free);
		local_garbage = (t_list *)0;
	}
	else
	{
		ft_lstadd_back(&(local_garbage), ft_lstnew((void *)any_elem));
	}
}
