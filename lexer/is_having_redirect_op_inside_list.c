/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_having_redirect_op_inside_list.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:40:40 by apayet            #+#    #+#             */
/*   Updated: 2022/09/01 12:41:04 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_having_redirect_op_inside_list(void)
{
	t_list			*lst;
	t_lexer_token	*node;

	lst = get_data((t_data *)0)->lexer_tokens;
	while (lst)
	{
		node = (t_lexer_token *)lst->content;
		if (is_op_of_redirect_fd(node->type))
			return (1);
		lst = lst->next;
	}
	return (0);
}
