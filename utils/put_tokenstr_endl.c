/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tokenstr_endl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:21:17 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 12:38:38 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function put to the STD_OUTPUT the token value
 * 
 * @param token 
 */
void	put_tokenstr_endl(t_lexer_token *token)
{
	if (token == (t_lexer_token *)0)
		return ;
	write(1, token->start_address, token->length);
	write(1, "\n", 1);
}
