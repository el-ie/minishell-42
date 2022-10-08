/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:23:13 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 19:31:43 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	init_vars_hd(t_list **hdoc, t_heredoc **node, t_lexer_token **token)
{
	*hdoc = (t_list *)0;
	*node = (t_heredoc *)0;
	*token = (t_lexer_token *)0;
}

static t_list	*set_node(t_list *cur, t_lexer_token *token, t_heredoc **p_node)
{
	t_heredoc	*node;

	node = *p_node;
	node->id_operator = token->id;
	node->filename = random_name_generator(16, TRUE);
	while (cur)
	{
		token = (t_lexer_token *)cur->content;
		if (token->type == TOKEN_TYPE_LIMITER)
			break ;
		else
			cur = cur->next;
	}
	node->limiter = dup_token_to_str(token, TRUE);
	node->expandable = is_limiter_expandable(node->limiter);
	if (node->expandable == 0)
		node->limiter = remove_quotes(node->limiter);
	return (cur);
}

/**
 * @brief 
 * 
 * @return int 
 */
void	register_heredoc(void)
{
	t_list			*hdoc_lst;
	t_list			*cur;
	t_lexer_token	*token;
	t_heredoc		*node;

	cur = get_data((t_data *)0)->lexer_tokens;
	init_vars_hd(&hdoc_lst, &node, &token);
	while (cur)
	{
		token = (t_lexer_token *)cur->content;
		if (token->type == OPERATOR_D_LESS)
		{
			node = create_node(NODE_TYPE_HEREDOC);
			check_malloc_fails_safe_exit((void *)node);
			cur = set_node(cur, token, &node);
			ft_lstadd_back(&hdoc_lst, ft_lstnew((void *)node));
			node = (t_heredoc *)0;
		}
		cur = cur->next;
	}
	get_data((t_data *)0)->here_doc_list = hdoc_lst;
}
