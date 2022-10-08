/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokennstrcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:00:45 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:38:26 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function compare the token to the char to be compare 
 * 
 * @param token 
 * @param to_comp 
 * @return int 
 */
int	tokennstrcmp(t_lexer_token *token, char *to_comp)
{
	if (token->length != ft_strlen(to_comp))
	{
		return (-1);
	}
	return (ft_strncmp(token->start_address, to_comp, token->length));
}
