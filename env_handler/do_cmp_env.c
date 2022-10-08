/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmp_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:51:31 by apayet            #+#    #+#             */
/*   Updated: 2022/08/13 12:00:48 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function compare a string and an env_var_token
 * 
 * @param key 
 * @param content 
 * @return int 
 */
int	do_cmp_env(const char *key, t_env_var_token *content)
{
	char	*start_addr;
	size_t	length;

	start_addr = content->var_name.start_address;
	length = content->var_name.length;
	return (ft_strncmp(key, start_addr, length));
}
