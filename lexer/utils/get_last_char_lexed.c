/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_char_lexed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:05:15 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:01:46 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Get the last char lexed object
 * 
 * @param cur 
 * @return char return null char if not exist
 */
char	get_last_char_lexed(t_list *cur)
{
	t_lexer_token	*token;

	token = (t_lexer_token *)0;
	if (cur == (t_list *)0)
		return ('\0');
	while (cur->next)
		cur = cur->next;
	token = (t_lexer_token *)cur->content;
	return ((token->end_address)[0]);
}
