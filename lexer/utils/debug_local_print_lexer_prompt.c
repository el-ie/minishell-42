/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_local_print_lexer_prompt.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:09:13 by apayet            #+#    #+#             */
/*   Updated: 2022/08/16 11:35:08 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	iter_on_token(void *iter)
{
	t_lexer_token	*node;

	node = (t_lexer_token *)iter;
	write(1, "\n", 1);
	if (node->type == TOKEN_TYPE_LITERAL)
		ft_putstr_fd("New lexer token found \t(literal)  : ", 1);
	if (node->type == TOKEN_TYPE_OPERATOR)
		ft_putstr_fd("New lexer token found \t(operator) : ", 1);
	if (node->type == TOKEN_TYPE_BLANK)
	{
		ft_putstr_fd("New lexer token found \t(blank)", 1);
		return ;
	}
	put_lexer_token_fd(node, 1);
}

/**
 * @brief For debug view each token
 * 			for disable use DEBUG eq to 0
 * 
 * @param state 
 */
void	debug_local_print_lexer_prompt(t_lexer_prompt *state)
{
	t_list	*list;

	if (DEBUG == FALSE)
		return ;
	list = state->list;
	ft_lstiter(list, &iter_on_token);
	write(1, "\n", 1);
}
