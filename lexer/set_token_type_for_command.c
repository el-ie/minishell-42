/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_type_for_command.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:37:19 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 14:43:51 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_list	*go_to_the_next_command(t_list *lst, t_lexer_token *token)
{
	lst = lst->next;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type == OPERATOR_PIPE)
			break ;
		lst = lst->next;
	}
	return (lst);
}

/**
 * @brief Set the token type for command object
 * 		NOTICE : if no command found, there continue ;)
 * 
 */
void	set_token_type_for_command(void)
{
	t_list			*lst;
	t_lexer_token	*token;

	lst = get_data((t_data *)0)->lexer_tokens;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type == TOKEN_TYPE_LITERAL)
		{
			token->type = TOKEN_TYPE_COMMAND;
			if (next_lexed_list_has_pipe(lst) == 1)
				lst = go_to_the_next_command(lst, token);
			else
				return ;
		}
		lst = lst->next;
	}
}
