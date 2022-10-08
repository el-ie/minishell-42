/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:10:46 by apayet            #+#    #+#             */
/*   Updated: 2022/09/15 14:51:10 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_lexer_prompt	init_lexer(char *prompt, t_lexer_token **node)
{
	t_lexer_prompt	state;

	ft_memset(&state, 0, sizeof(state));
	state.type[0] = TOKEN_TYPE_LITERAL;
	state.type[1] = TOKEN_TYPE_OPERATOR;
	state.type[2] = TOKEN_TYPE_BLANK;
	state.prompt = prompt;
	*node = (t_lexer_token *)0;
	return (state);
}

void	tokenize_prompt(char *prompt)
{
	t_lexer_prompt	state;
	t_lexer_token	*node;

	state = init_lexer(prompt, &node);
	while (prompt[state.i])
	{
		node = create_node(NODE_TYPE_LEXER_TOKEN);
		set_head_of_token(&state, node);
		if (node->type == TOKEN_TYPE_LITERAL)
			set_content_literal(&state, node);
		if (node->type == TOKEN_TYPE_OPERATOR)
			set_content_operator(&state, node);
		if (node->type == TOKEN_TYPE_BLANK)
			set_content_blank(&state, node);
		if (set_end_of_token(&state, &node) == 1)
			break ;
	}
	debug_local_print_lexer_prompt(&state);
	get_data((t_data *)0)->lexer_tokens = &(state.list)[0];
}
