/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_content_to_redirect_fd_node.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:53:05 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:24:46 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_content_to_redirect_fd_node(t_redirect **a, t_list *lst, int len)
{
	int				i;
	int				type;
	t_lexer_token	*token;
	t_redirect_fd	*node;
	t_redirect		**array;

	if (len == 0)
		return ;
	i = 0;
	array = a;
	while (i < len)
	{
		token = (t_lexer_token *)lst->content;
		type = token->type;
		if (type >= OPERATOR_PIPE && type < OPERATOR_MAX_VALUE)
		{
			if (OPERATOR_PIPE == type)
				break ;
			node = (t_redirect_fd *)array[i]->content;
			set_op_to_redirect_fd_node(node, lst);
			set_type_to_redirect_fd_node(node, type);
			i++;
		}
		lst = lst->next;
	}
}
