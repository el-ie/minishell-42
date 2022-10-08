/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtoken_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:48:38 by apayet            #+#    #+#             */
/*   Updated: 2022/09/22 16:49:33 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_list	*new_sub_token(t_list *splitted_link, t_env_var_token *env_tok)
{
	t_lexer_token	*token;

	token = (t_lexer_token *)0;
	token = create_node(NODE_TYPE_LEXER_TOKEN);
	ft_lstadd_back(&splitted_link, ft_lstnew(token));
	(void)env_tok;
	return (splitted_link);
}

void	subtoken_update(t_env_var_token **p_content, int sub_tokenized)
{
	t_env_var_token	*content;

	content = *p_content;
	if (sub_tokenized != 0)
		ft_lstclear(&(content->splited_content), &free);
	content->splited_content = (t_list *)0;
	content->splited_content = new_sub_token(content->splited_content, NULL);
}
