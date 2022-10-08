/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_type_for_redirect_fd_filename.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:43:26 by apayet            #+#    #+#             */
/*   Updated: 2022/10/04 12:50:36 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_token_type_for_redirect_fd_filename(void)
{
	t_list			*lst;
	t_lexer_token	*token;

	lst = get_data((t_data *)0)->lexer_tokens;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (is_op_of_redirect_fd(token->type))
		{
			lst = lst->next;
			while (lst)
			{
				token = lst->content;
				if (token->type == TOKEN_TYPE_BLANK)
					lst = lst->next;
				else
					break ;
			}
			token->type = TOKEN_TYPE_FILENAME;
		}
		lst = lst->next;
	}
}
