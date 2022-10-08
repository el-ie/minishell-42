/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_tokenisation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:20:46 by apayet            #+#    #+#             */
/*   Updated: 2022/09/22 17:00:59 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	chk_before_splt_val(char *line, t_lexer_token *token, void *p_env_c)
{
	char				first_key_empty;
	t_state_lex_env		*env_c;

	env_c = (t_state_lex_env *)p_env_c;
	first_key_empty = 0;
	first_key_empty = *(token->start_address);
	if (first_key_empty == ':')
	{
		env_c->_split = env_c->_split + 1;
		token->start_address = line + env_c->_split;
	}
}

static void	first_token(char *line, t_lexer_token *tok, t_state_lex_env *env_c)
{
	int	counted;

	counted = 0;
	env_c->_split += 1;
	tok->start_address = line + env_c->_split;
	chk_before_splt_val(line, tok, (void *)env_c);
	counted = count_until_char_found(line + env_c->_split, ':');
	env_c->_split = env_c->_split + counted;
	tok->end_address = line + env_c->_split;
	tok->length = tok->end_address - tok->start_address;
}

void	sub_tokenisation(char *line, t_list **head, t_state_lex_env *env_c)
{
	t_list			*cur;
	t_lexer_token	*token;

	cur = *head;
	if (cur == (t_list *)0)
		return ;
	token = (t_lexer_token *)cur->content;
	first_token(line, token, env_c);
	while (check_end_of_value(token) != 1)
	{
		token = create_node(NODE_TYPE_LEXER_TOKEN);
		ft_lstadd_back(head, ft_lstnew((void *)token));
		env_c->_split += 1;
		token->start_address = env_c->_split + line;
		env_c->_split += count_until_char_found(line + env_c->_split, ':');
		token->end_address = line + env_c->_split;
		token->length = token->end_address - token->start_address;
		if (check_end_of_value(token) == 1)
			break ;
	}
}
