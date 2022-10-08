/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args_array_from_token_list.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:32:51 by apayet            #+#    #+#             */
/*   Updated: 2022/09/02 22:45:44 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @deprecated first implementation may be unsused
 * @brief This function is used for the parser, it is used to have a (char **)
 * 			From token list of the lexer
 * 
 * 		
 * 
 * @param node The token list 
 * @return char** the array to pass to execve, seconde parameter
 */
char	**extract_args_array_from_token_list(t_list *node)
{
	(void)node ;
	return (NULL);
}
