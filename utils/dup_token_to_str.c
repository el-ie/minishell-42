/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_token_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:43:31 by apayet            #+#    #+#             */
/*   Updated: 2022/08/15 12:44:03 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief  This function duplicate the content of a token
 *
 * 
 * @param token 
 * @param regular_malloc use 1 for the usage of the regular malloc
 *						 or use 0 for the main garbage collector
 * @return char* 
 */
char	*dup_token_to_str(t_lexer_token *token, int regular_malloc)
{
	char	*res;

	res = (char *)0;
	if (regular_malloc == 1)
		res = malloc(sizeof(char) *(token->length + 1));
	else
		res = ft_malloc(sizeof(char) * (token->length + 1));
	if (!res)
	{
		set_error_state(MALLOC_ERROR);
		return ((char *)0);
	}
	ft_strlcpy(res, token->start_address, token->length + 1);
	return (res);
}
