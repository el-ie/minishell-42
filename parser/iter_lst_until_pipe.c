/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_lst_until_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:02:18 by apayet            #+#    #+#             */
/*   Updated: 2022/09/08 15:43:04 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*iter_lst_until_pipe(t_list *lst)
{
	t_lexer_token	*token;

	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type == OPERATOR_PIPE)
		{
			if (lst->next)
				return (lst->next);
			else
				return ((t_list *)0);
		}
		lst = lst->next;
	}
	return ((t_list *)0);
}
