/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_for_ast_tree.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:20:45 by apayet            #+#    #+#             */
/*   Updated: 2022/09/03 17:21:41 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_command_for_ast_tree(t_list *lst)
{
	t_lexer_token	*token;
	char			*ret_value;

	ret_value = (char *)0;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type == TOKEN_TYPE_COMMAND)
		{
			ret_value = dup_token_to_str(token, TRUE);
			return (ret_value);
		}
		lst = lst->next;
	}
	return (ret_value);
}
