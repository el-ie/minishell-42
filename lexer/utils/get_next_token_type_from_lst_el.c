/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_token_type_from_lst_el.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:31:05 by apayet            #+#    #+#             */
/*   Updated: 2022/10/04 13:17:53 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_next_token_type_from_lst_el(t_list *el)
{
	t_lexer_token	*token;

	token = get_next_lexer_token_not_blank(el);
	if (!token)
		return (-1);
	if (token->type == TOKEN_TYPE_LITERAL)
		return (TOKEN_TYPE_LITERAL);
	if (token->type == OPERATOR_PIPE)
		return (OPERATOR_PIPE);
	if (token->type == TOKEN_TYPE_LIMITER)
		return (TOKEN_TYPE_LIMITER);
	if (token->type < TOKEN_TYPE_UNDEFINED)
		return (token->type);
	return (TOKEN_TYPE_UNDEFINED);
}
