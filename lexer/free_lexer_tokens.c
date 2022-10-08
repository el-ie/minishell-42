/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer_tokens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:19:31 by apayet            #+#    #+#             */
/*   Updated: 2022/09/08 17:12:43 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_freeable_token(void *content)
{
	t_lexer_token	*token;

	token = (t_lexer_token *)content;
	if (token->free_able)
		free(token->start_address);
}

void	free_lexer_tokens(void)
{
	ft_lstiter(get_data((t_data *)0)->lexer_tokens, &free_freeable_token);
	ft_lstclear(&(get_data((t_data *)0)->lexer_tokens), &free);
}
