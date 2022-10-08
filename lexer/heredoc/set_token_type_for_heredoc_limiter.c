/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_type_for_heredoc_limiter.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:25:32 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 11:09:16 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief	After checking the syntax of heredoc limiter
 *  we set the token of the limiter to TOKEN_TYPE_LIMITER
 * 
 */
void	set_token_type_for_heredoc_limiter(void)
{
	t_list			*cur_tok;
	t_lexer_token	*token;

	cur_tok = get_data((t_data *)0)->lexer_tokens;
	while (cur_tok)
	{
		token = (t_lexer_token *)cur_tok->content;
		if (token->type == OPERATOR_D_LESS)
		{
			cur_tok = cur_tok->next;
			while (cur_tok)
			{
				token = cur_tok->content;
				if (token->type == TOKEN_TYPE_BLANK)
					cur_tok = cur_tok->next;
				else
					break ;
			}
			token->type = TOKEN_TYPE_LIMITER;
		}
		cur_tok = cur_tok->next;
	}
}
