/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_content_literal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:20:25 by apayet            #+#    #+#             */
/*   Updated: 2022/08/16 11:37:47 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	s_quote_trim_until_next(t_lexer_prompt *state)
{
	if (is_char_single_quote(state->prompt[state->i]))
	{
		if (state->prompt[state->i])
				state->i = state->i + 1;
		while (is_char_single_quote(state->prompt[state->i]) != 1)
			state->i = state->i + 1;
	}
}

static void	d_quote_trim_until_next(t_lexer_prompt *state)
{
	if (is_char_double_quote(state->prompt[state->i]))
	{
		if (state->prompt[state->i])
				state->i = state->i + 1;
		while (is_char_double_quote(state->prompt[state->i]) != 1)
			state->i = state->i + 1;
	}
}

void	set_content_literal(t_lexer_prompt *state, t_lexer_token *node)
{
	while (state->prompt[state->i])
	{
		s_quote_trim_until_next(state);
		d_quote_trim_until_next(state);
		if (is_metachar(state->prompt[state->i])
			&& state->s_quote_enabled == 0
			&& state->d_quote_enabled == 0)
			break ;
		state->i = state->i + 1;
	}
	node->end_address = state->prompt + state->i;
}
