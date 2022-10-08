/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:06:21 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 16:45:53 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 	This function is design to get the 
 * 			content value of the key enntered for the env
 * 
 * @param key 	The variable of the environnement searched
 * @return char*  A string malloc'd or null if not found
 */
char	*get_env_value(const char *key)
{
	t_list			*cur;
	size_t			key_length;
	t_env_var_token	*cnt;
	char			*res;

	res = (char *)0;
	cur = get_env_t_list();
	if (cur == (t_list *)0 || key == (const char *)0)
		return ((char *)0);
	key_length = ft_strlen(key);
	while (cur)
	{
		cnt = (t_env_var_token *)cur->content;
		if (do_cmp_env(key, cnt) == 0 && key_length == cnt->var_name.length)
		{			
			if (is_cmp_perfect_match(key_length, cnt))
			{
				res = (char *)dup_token_to_str(&(cnt->full_content), 0);
				check_malloc_fails_safe_exit((void *)res);
				return (res);
			}
		}
		cur = cur->next;
	}
	return ((char *)0);
}
