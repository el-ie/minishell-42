/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:17:14 by apayet            #+#    #+#             */
/*   Updated: 2022/08/13 12:01:05 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	get_token_length(t_lexer_token *token)
{
	if (token->start_address == (char *)0 || token->end_address == (char *)0)
		return (0);
	return (token->end_address - token->start_address);
}
