/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_next_is_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:07:13 by apayet            #+#    #+#             */
/*   Updated: 2022/07/06 16:12:50 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief This function return a boolean value for the operator,
 * 			 usefull for the parser 
 * @param lexer_node this is the current node, it automatically check the next
 * @return int 			return true(!=0) or false(==0) if the node exist
 * 						it return (0) if the node->next is NULL
 */
int	lexer_next_is_op(t_list *lexer_node)
{
	t_list	*lexer_next;

	lexer_next = lexer_node->next;
	if (lexer_next)
		return (((t_lexer_token *)lexer_next->content)->type == LEX_OPERATOR);
	return (0);
}
