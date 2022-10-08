/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_spec_op_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:02:41 by apayet            #+#    #+#             */
/*   Updated: 2022/09/02 22:02:31 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// check usage for know if deprecated
/**
 * 
 * @brief this function permit to know wat type of operator the token is
 * 
 * @param lexer the t_list element of the lexer list /!\ the element not the head
 * @return int 	return the OPERATOR_VALUE
 */
int	get_spec_op_value(t_list *lexer)
{
	if (tokennstrcmp((t_lexer_token *)lexer->content, "|") == 0)
		return (OPERATOR_PIPE);
	if (tokennstrcmp((t_lexer_token *)lexer->content, ">>") == 0
		&& get_token_length(lexer->content) == ft_strlen(">>"))
		return (OPERATOR_D_GREAT);
	if (tokennstrcmp((t_lexer_token *)lexer->content, "<<") == 0
		&& get_token_length(lexer->content) == ft_strlen("<<"))
		return (OPERATOR_D_LESS);
	if (tokennstrcmp((t_lexer_token *)lexer->content, "<") == 0)
		return (OPERATOR_LESS);
	if (tokennstrcmp((t_lexer_token *)lexer->content, ">") == 0)
		return (OPERATOR_GREAT);
	return (OPERATOR_UNDEFINED);
}
