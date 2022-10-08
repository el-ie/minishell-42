/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prelexer_for_expand_prompt.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:55:16 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 19:25:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	set_head_of_token_prelex(t_prelex_state *state, t_lexer_token *n)
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

static void	set_content_literal_prelex(t_prelex_state *state, t_lexer_token *n)
{
	t_lexer_token	*node;

	node = n;
	while (state->prompt[state->i])
	{	
		if (is_char_single_quote(state->prompt[state->i])
			&& state->s_quote_enabled == 0)
		{
			state->s_quote_enabled = 1;
			if (state->prompt[state->i])
				state->i = state->i + 1;
		}
		if (is_char_single_quote(state->prompt[state->i])
			&& state->s_quote_enabled == 1)
		{
			state->s_quote_enabled = 0;
			if (state->prompt[state->i])
				state->i = state->i + 1;
		}
		if (is_char_dollar(state->prompt[state->i])
			&& state->s_quote_enabled == 0)
			break ;
		state->i = state->i + 1;
	}
	node->end_address = state->prompt + state->i;
}

static void	set_content_variable_prelex(t_prelex_state *state, t_lexer_token *n)
{
	t_lexer_token	*node;

	node = n;
	if (ft_isdigit(state->prompt[state->i]) == 0)
		case_is_digit_set_content(state);
	else
	{
		if (state->prompt[state->i]
			&& ft_isdigit(state->prompt[state->i]))
			state->i = state->i + 1;
		node->type = TOKEN_TYPE_LITERAL;
		node->start_address = state->prompt + state->i;
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

/**
 * @brief Set the end of token object
 * 
 * @param sub_list 
 * @param node 
 * @return int if return 1, the loop stop
 */
static int	set_end_of_token_prelex(t_prelex_state *state, t_lexer_token **p_n)
{
	t_lexer_token	*node;

	node = *p_n;
	node->length = node->end_address - node->start_address;
	ft_lstadd_back(&(state->sub_list), ft_lstnew((void *)node));
	*p_n = (t_lexer_token *)0;
	if (get_last_char_lexed(state->sub_list) == '\0')
		return (1);
	return (0);
}

/**
 * @brief lexing first prompt if needed
 * 
 * @ref Environment variable names used by the utilities in the Shell and 
 * Utilities
 *  volume of IEEE Std 1003.1-2001 consist solely of uppercase letters, digits,
 *  and the '_' (underscore) from the characters defined in Portable Character 
 * Set and do not begin with a digit.
 * Other characters may be permitted by an implementation; applications shall
 * tolerate the presence of such names. Uppercase and lowercase letters shall 
 * retain their unique identities and shall not be folded together. The name 
 * space of environment variable names containing lowercase letters is reserved
 *  for applications. Applications can define any environment variables with 
 * names from this name space without modifying the behavior of the standard
 *  utilities.
 * 
 * @param p_prompt will be rewrited and leak free
 *  * 	WARNING : DO NO MODIFY THE CONDITION node->type == state.type[n]
 */
char	*prelexer_for_expand_prompt(char *p_prompt)
{
	t_prelex_state	state;
	t_lexer_token	*node;

	ft_memset(&state, 0, sizeof(state));
	state.prompt = p_prompt;
	node = (t_lexer_token *)0;
	state.type[0] = TOKEN_TYPE_LITERAL;
	state.type[1] = TOKEN_TYPE_VARIABLE;
	if (prompt_need_expand(state.prompt) == 0)
		return (p_prompt);
	while (state.prompt[state.i])
	{
		node = create_node(NODE_TYPE_LEXER_TOKEN);
		set_head_of_token_prelex(&state, node);
		if (node->type == state.type[0])
			set_content_literal_prelex(&state, node);
		if (node->type == state.type[1])
			set_content_variable_prelex(&state, node);
		if (set_end_of_token_prelex(&state, &node) == 1)
			break ;
	}
	state.prompt = convert_prelexed_to_str(state.sub_list);
	ft_lstclear(&(state.sub_list), &free);
	state.sub_list = (t_list *)0;
	return (state.prompt);
}
