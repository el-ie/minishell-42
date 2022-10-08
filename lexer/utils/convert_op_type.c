/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_op_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:11:16 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 11:58:59 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	convert_op_type(t_list *cur)
{
	t_lexer_token	*token;

	token = (t_lexer_token *)cur->content;
	token->type = get_spec_op_value(cur);
}
