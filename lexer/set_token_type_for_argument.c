/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_type_for_argument.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:01:26 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 18:02:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Set the token type for argument object
 * 	Argument is linked directly
 * 	This is teh last step for the lexer 
 */
void	set_token_type_for_argument(void)
{
	t_list			*lst;
	t_lexer_token	*token;

	lst = get_data((t_data *)0)->lexer_tokens;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type == TOKEN_TYPE_LITERAL)
		{
			token->type = TOKEN_TYPE_ARGUMENT;
		}
		lst = lst->next;
	}
}
