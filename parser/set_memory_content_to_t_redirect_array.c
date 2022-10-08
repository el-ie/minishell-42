/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_memory_content_to_t_redirect_array.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:07 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:23:46 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_mem_content_redirect_array(t_redirect **a, t_list *lst, int len)
{
	int				i;
	t_lexer_token	*token;
	t_redirect		**array;

	if (len == 0)
		return ;
	i = 0;
	array = a;
	while (i < len)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type >= OPERATOR_PIPE && token->type < OPERATOR_MAX_VALUE)
		{
			set_memory_content_to_t_redirect_node(array[i]);
			i++;
		}
		lst = lst->next;
	}
}
