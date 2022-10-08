/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:41:11 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:39:44 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Set the head of token heredoc object
 * 			Create the first part of the token
 * 
 * @param state 
 * @param node 
 */
static void	set_head_of_token_heredoc(t_prelex_state *state, t_lexer_token *n)
{
	char			(*get)(t_list*);
	t_lexer_token	*node;

	node = n;
	get = &get_last_char_lexed;
	if (ft_lstsize(state->sub_list) == 0)
	{
		node->id = 0;
		node->type = state->type[is_char_dollar(state->prompt[0])];
		node->start_address = state->prompt + state->i;
		state->i = state->i + 1;
	}
	else
	{
		node->id = ft_lstsize(state->sub_list);
		node->type = state->type[is_char_dollar(get(state->sub_list))];
		node->start_address = state->prompt + state->i;
		state->i = state->i + 1;
	}
}

/**
 * @brief Set the content literal heredoc object
 * 
 * @param state 
 * @param node 
 */
static void	set_content_literal_heredoc(t_prelex_state *s, t_lexer_token *n)
{
	t_lexer_token	*node;
	t_prelex_state	*state;

	node = n;
	state = s;
	while (state->prompt[state->i])
	{	
		if (is_char_dollar(state->prompt[state->i])
			&& state->s_quote_enabled == 0)
			break ;
		state->i = state->i + 1;
	}
	node->end_address = state->prompt + state->i;
}

/**
 * @brief Set the content variable heredoc object
 * 
 * @param state 
 * @param node 
 */
static void	set_content_variable_heredoc(t_prelex_state *s, t_lexer_token *n)
{
	t_prelex_state	*state;
	t_lexer_token	*node;

	state = s;
	node = n;
	if (ft_isdigit(state->prompt[state->i]) == 0)
	{
		while (state->prompt[state->i])
		{
			if (is_char_allowed_env_var(state->prompt[state->i]) == 1)
				state->i = state->i + 1;
			else
				break ;
		}
	}
	node->end_address = state->prompt + state->i;
}

static int	set_end_of_token_heredoc(t_prelex_state *state, t_lexer_token **n)
{
	t_lexer_token	*node;

	node = *n;
	node->length = node->end_address - node->start_address;
	ft_lstadd_back(&(state->sub_list), ft_lstnew((void *)node));
	*n = (t_lexer_token *)0;
	if (get_last_char_lexed(state->sub_list) == '\0')
		return (1);
	return (0);
}

/**
 * @brief This function is quite similiar than prelexer_for_expand_prompt
 * 			except some trigger for quotes
 * 		That is why we use t_prelex_state
 * 	WARNING : DO NO MODIFY THE CONDITION node->type == state.type[n]
 */
char	*expand_heredoc(char *p_content)
{
	t_prelex_state	state;
	t_lexer_token	*node;

	ft_memset(&state, 0, sizeof(state));
	state.prompt = p_content;
	state.type[0] = TOKEN_TYPE_LITERAL;
	state.type[1] = TOKEN_TYPE_VARIABLE;
	while (state.prompt[state.i])
	{
		node = create_node(NODE_TYPE_LEXER_TOKEN);
		set_head_of_token_heredoc(&state, node);
		if (node->type == state.type[0])
			set_content_literal_heredoc(&state, node);
		if (node->type == state.type[1])
			set_content_variable_heredoc(&state, node);
		if (set_end_of_token_heredoc(&state, &node) == 1)
			break ;
	}
	state.prompt = convert_prelexed_to_str(state.sub_list);
	ft_lstclear(&(state.sub_list), &free);
	state.sub_list = (t_list *)0;
	return (state.prompt);
}
