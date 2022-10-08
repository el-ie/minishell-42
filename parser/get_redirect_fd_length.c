/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_fd_length.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:02:33 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 13:25:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_redirect_fd_length(t_list *lst)
{
	int				count;
	t_lexer_token	*token;

	count = 0;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type > OPERATOR_PIPE && token->type < OPERATOR_MAX_VALUE)
			count++;
		else if (token->type == OPERATOR_PIPE)
			return (count + 1);
		lst = lst->next;
	}
	return (count);
}
