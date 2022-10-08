/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_head_of_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:18:43 by apayet            #+#    #+#             */
/*   Updated: 2022/08/16 11:37:55 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_head_of_token(t_lexer_prompt *state, t_lexer_token *node)
{
	char	(*get)(t_list *);

	get = &get_last_char_lexed;
	if (ft_lstsize(state->list) == 0)
	{
		node->id = 0;
		node->type = state->type[get_chartype_id(state->prompt[0])];
	}
	else
	{
		node->id = ft_lstsize(state->list);
		node->type = state->type[get_chartype_id(get(state->list))];
	}
	node->start_address = state->prompt + state->i;
}
