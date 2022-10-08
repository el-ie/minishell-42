/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_heredoc_having_limiter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:26:43 by apayet            #+#    #+#             */
/*   Updated: 2022/10/04 13:29:29 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	display_error_limiter(t_lexer_token *token, t_list *cur_tok)
{
	ft_putstr_fd("2minishell : parse error near '", 2);
	token = get_next_lexer_token_not_blank(cur_tok);
	if (token)
		put_lexer_token_fd(token, 2);
	else
		ft_putstr_fd("\\n", 2);
	ft_putstr_fd("'\n", 2);
	get_data((t_data *)0)->status_last_cmd = 2;
	return (0);
}

/**
 * @brief Just checking the syntax after the limiter and return false if need 
 * 			to stop the process
 * 
 * @return int 
 */
int	is_heredoc_having_limiter(void)
{
	t_list			*cur_tok;
	t_lexer_token	*token;
	int				type;

	cur_tok = get_data((t_data *)0)->lexer_tokens;
	while (cur_tok)
	{
		token = (t_lexer_token *)cur_tok->content;
		if (token->type == OPERATOR_D_LESS)
		{
			type = get_next_token_type_from_lst_el(cur_tok);
			if (type != TOKEN_TYPE_LITERAL || type == -1)
				return (display_error_limiter(token, cur_tok));
		}
		cur_tok = cur_tok->next;
	}
	return (1);
}
