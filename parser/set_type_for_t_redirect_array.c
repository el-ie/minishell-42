/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type_for_t_redirect_array.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:00:31 by apayet            #+#    #+#             */
/*   Updated: 2022/09/06 17:00:53 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_type_for_t_redirect_array(t_redirect **array, t_list *lst, int len)
{
	int				i;
	t_lexer_token	*token;

	if (len == 0)
		return ;
	i = 0;
	while (i < len)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type >= OPERATOR_PIPE && token->type < OPERATOR_MAX_VALUE)
		{
			set_type_to_redirect_node(array[i], token->type);
			i++;
		}
		lst = lst->next;
	}
}
