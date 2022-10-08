/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_token_limiter_to_token_filename.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:09:39 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 18:10:11 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function is used when then end is know as '\0'
 * 			just put a len with strlen 
 * 
 * @param token 
 * @param len 
 */
static void	set_token_end_with_len(t_lexer_token *token, int len)
{
	token->end_address = token->start_address + len;
}

void	convert_token_limiter_to_token_filename(void)
{
	t_list			*lst;
	t_lexer_token	*token;
	t_list			*hdoc_lst;
	t_heredoc		*node;

	lst = get_data((t_data *)0)->lexer_tokens;
	hdoc_lst = get_data((t_data *)0)->here_doc_list;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type == TOKEN_TYPE_LIMITER)
		{
			token->type = TOKEN_TYPE_FILENAME;
			node = (t_heredoc *)hdoc_lst->content;
			token->start_address = node->filename;
			set_token_end_with_len(token, ft_strlen(node->filename));
			token->length = token->end_address - token->start_address;
			hdoc_lst = hdoc_lst->next;
			if (hdoc_lst == (t_list *)0)
				return ;
		}
		lst = lst->next;
	}
}
