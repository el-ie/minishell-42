/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmp_perfect_match.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:53:11 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 16:46:54 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function determine after do_cmp if the token is right ended 
 * 			For avoiding a same sequence's char 
 * 				Example strcmp("test", "tested") will have a retur value of 0
 * 				so we need to check with is_cmp_perfect_match
 * 			In the parser it is ended with '=' but can bee NULL char 
 * 	
 * @param key_length 
 * @param content 
 * @return int 
 */
int	is_cmp_perfect_match(int key_length, t_env_var_token *content)
{
	char	*start_addr;

	start_addr = content->var_name.start_address;
	if ((long unsigned int)key_length != content->var_name.length)
	{
		return (0);
	}
	return ((start_addr[key_length] == '=') || (start_addr[key_length] == 0));
}
