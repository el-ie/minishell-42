/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subject_boudary_reserved_word.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:47:15 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 10:00:29 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief tokennstrcmp will return 0 if equals other if not equals
 * 			this function stop and return 1 when Reserved word founded;
 * 
 * @param token 
 */
static int	do_compare(t_lexer_token *token)
{
	char	*(*ref_comp)(int, int);
	int		ref_i;
	int		comp_res;

	ref_comp = &get_reserved_word_array;
	ref_i = 0;
	while (ref_i < R_MAX)
	{
		comp_res = tokennstrcmp(token, ref_comp(ref_i, FALSE));
		if (comp_res == 0)
		{
			put_subject_boundary_error_endl(ref_comp(ref_i, FALSE));
			return (1);
		}
		ref_i += 1;
	}
	return (0);
}

/**
 * @brief Reserved word apply on LITERAL, 
 * 			LIMITER of heredoc is not a reserved value 
 * 
 * @return int return 1 if subject boudary detect a reserved word 
 * 				return 0 if no reserved word found << the correct value 
 */
int	check_subject_boundary_reserved_word(void)
{
	t_list			*lst;
	t_lexer_token	*token;

	lst = get_data((t_data *)0)->lexer_tokens;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type == TOKEN_TYPE_COMMAND)
		{
			if (do_compare(token) == 1)
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}
