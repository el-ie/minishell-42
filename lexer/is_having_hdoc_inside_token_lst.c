/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_having_hdoc_inside_token_lst.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:15:13 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:41:57 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_having_hdoc_inside_token_lst(void)
{
	t_list			*lst;
	t_lexer_token	*node;

	lst = get_data((t_data *)0)->lexer_tokens;
	while (lst)
	{
		node = (t_lexer_token *)lst->content;
		if (node->type == OPERATOR_D_LESS)
			return (1);
		lst = lst->next;
	}
	return (0);
}
