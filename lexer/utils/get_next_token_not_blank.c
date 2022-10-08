/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token_not_blank.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:29:48 by apayet            #+#    #+#             */
/*   Updated: 2022/10/04 15:35:12 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Get the next lexer token not blank object
 * 
 * @param el 
 * @return t_lexer_token* 
 */
t_lexer_token	*get_next_lexer_token_not_blank(t_list *el)
{
	t_lexer_token	*token;

	if (el == (t_list *)0)
		return ((t_lexer_token *)0);
	el = el->next;
	while (el)
	{
		token = (t_lexer_token *)el->content;
		if (token->type == TOKEN_TYPE_BLANK)
			el = el->next;
		else
			break ;
	}
	if (el)
		return ((t_lexer_token *)el->content);
	return ((t_lexer_token *)0);
}
