/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_parsed_after_extraction_args.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:09:33 by apayet            #+#    #+#             */
/*   Updated: 2022/07/08 19:26:08 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief When doing the extraction of args from the tokenisation,
 * 	it is unescessary to do one thinng on this node,
 *		This function just set the new adress of the list
 * 
 * @param partial_lst 
 */
void	skip_parsed_after_extraction_args(t_list **partial_lst)
{
	t_list			*skip;
	t_lexer_token	*token;

	skip = *partial_lst;
	if (!skip && skip->content == (void *)0)
		return ;
	token = (t_lexer_token *)skip->content;
	while (skip && token->type == LEX_WORD)
	{
		token = (t_lexer_token *)skip->content;
		if (token->type == LEX_OPERATOR)
		{
			ft_printf("Type operator found inside the function skip\n");
			*partial_lst = skip;
			return ;
		}
		skip = skip->next;
	}
	*partial_lst = skip;
}
