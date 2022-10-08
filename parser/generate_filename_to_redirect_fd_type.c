/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_filename_to_redirect_fd_type.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:50:00 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 10:51:25 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	gen_filename_redirect_fd(t_redirect **array, t_list *lst, int len)
{
	int				i;
	t_lexer_token	*token;
	t_redirect_fd	*node;

	if (len == 0)
		return ;
	i = 0;
	while (i < len)
	{
		token = (t_lexer_token *)lst->content;
		if (OPERATOR_PIPE == token->type)
			break ;
		if (token->type == TOKEN_TYPE_FILENAME)
		{
			node = (t_redirect_fd *)array[i]->content;
			set_filename_to_redirect_fd_node(node, token);
			set_fd_to_redirect_fd(node);
			i++;
		}
		lst = lst->next;
	}
}
