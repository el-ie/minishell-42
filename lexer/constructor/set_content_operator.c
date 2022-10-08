/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_content_operator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:21:52 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:46:28 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_content_operator(t_lexer_prompt *state, t_lexer_token *node)
{
	if (state->prompt[state->i + 1]
		&& state->prompt[state->i] == state->prompt[state->i + 1])
		state->i = state->i + 2;
	else
		state->i = state->i + 1;
	node->end_address = state->prompt + state->i;
}
