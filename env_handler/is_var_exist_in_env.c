/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_var_exist_in_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:18:50 by apayet            #+#    #+#             */
/*   Updated: 2022/07/07 14:03:15 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function permit to know if the var exist in the parsed env
 * 
 * @param key the var name, must be equal length, no splace and no more char
 * @return int the boolean representation
 */
int	is_var_exist_in_env(const char *key)
{
	t_list			*cur;
	size_t			key_length;
	t_env_var_token	*content;

	cur = get_env_t_list();
	if (cur == (t_list *)0)
		return (0);
	key_length = ft_strlen(key);
	while (cur)
	{
		content = (t_env_var_token *)cur->content;
		if (do_cmp_env(key, content) == 0)
			if (is_cmp_perfect_match(key_length, content))
				return (1);
		cur = cur->next;
	}
	return (0);
}
