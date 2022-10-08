/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_end_of_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:19:42 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:46:49 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	set_end_of_token(t_lexer_prompt *state, t_lexer_token **p_node)
{
	t_lexer_token	*token;

	token = *p_node;
	token->length = token->end_address - token->start_address;
	ft_lstadd_back(&(state->list), ft_lstnew((void *)token));
	*p_node = (t_lexer_token *)0;
	if (get_last_char_lexed(state->list) == '\0')
		return (1);
	return (0);
}
