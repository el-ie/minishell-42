/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_t_list_el_operator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:04:41 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:00:50 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_t_list_el_operator(t_list *cur)
{
	t_lexer_token	*el;

	el = (t_lexer_token *)cur->content;
	return (el->type == TOKEN_TYPE_OPERATOR || el->type < TOKEN_TYPE_UNDEFINED);
}
