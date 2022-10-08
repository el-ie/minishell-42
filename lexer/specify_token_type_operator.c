/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specify_token_type_operator.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:27:53 by apayet            #+#    #+#             */
/*   Updated: 2022/08/23 13:44:33 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 	This function check each TOKEN_TYPE_OPERATOR to 
 * 			OPERATOR_TYPE who is more specific 
 *			see enum token_type and e_spec_op_value 
 *	
 *			This function call the get_spec_op_value inside ast/parser_utils	
 */
void	specify_token_type_operator(void)
{
	t_lexer_token	*token;
	t_list			*lst;

	lst = get_data((t_data *)0)->lexer_tokens;
	if (lst == (t_list *)0)
		return ;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type == TOKEN_TYPE_OPERATOR)
			token->type = get_spec_op_value(lst);
		lst = lst->next;
	}
}
