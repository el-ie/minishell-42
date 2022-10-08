/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_content_blank.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:22:39 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:46:11 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_content_blank(t_lexer_prompt *state, t_lexer_token *node)
{
	while (state->prompt[state->i])
	{
		if (get_chartype_id(state->prompt[state->i]) == 2)
			state->i = state->i + 1;
		else
			break ;
	}
	node->end_address = state->i + state->prompt;
}
