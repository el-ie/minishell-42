/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_env_token_malloced.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:20:00 by apayet            #+#    #+#             */
/*   Updated: 2022/09/20 12:40:51 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_token_key_value_malloced(t_env_var_token *content)
{
	char	*start_addr;

	start_addr = content->var_name.start_address;
	return (start_addr[content->var_name.length] == '\0');
}

int	is_env_token_malloced(const char *key)
{
	t_list			*cur;
	t_env_var_token	*content;
	size_t			key_length;

	cur = get_env_t_list();
	if (cur == (t_list *)0)
		return (0);
	key_length = ft_strlen(key);
	while (cur)
	{
		content = (t_env_var_token *)cur->content;
		if (do_cmp_env(key, content) == 0)
		{
			if (is_cmp_perfect_match(key_length, content))
			{
				if (is_token_key_value_malloced(content))
					return (1);
				else
					return (0);
			}
		}
		cur = cur->next;
	}
	return (0);
}
