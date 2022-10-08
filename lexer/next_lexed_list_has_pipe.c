/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_lexed_list_has_pipe.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:42:35 by apayet            #+#    #+#             */
/*   Updated: 2022/09/12 16:58:11 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	next_lexed_list_has_pipe(t_list *cur)
{
	t_lexer_token	*token;

	while (cur)
	{
		token = (t_lexer_token *)cur->content;
		if (token->type == OPERATOR_PIPE)
			return (1);
		cur = cur->next;
	}
	return (0);
}
