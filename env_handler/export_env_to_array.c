/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:34:44 by apayet            #+#    #+#             */
/*   Updated: 2022/09/20 09:31:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*reg_local_garbage(char	*ref, int is_free_act)
{
	static t_list	*local_garbage = (t_list *)0;

	if (is_free_act)
	{
		ft_lstclear(&local_garbage, &free);
		local_garbage = (t_list *)0;
		return ((char *)0);
	}
	else
		ft_lstadd_back(&local_garbage, ft_lstnew((void *)ref));
	return (ref);
}

static char	*concat_tokens(t_env_var_token *content)
{
	char	*full;
	char	*key;
	char	*value;

	full = (char *)0;
	key = (char *)0;
	value = (char *)0;
	full = reg_local_garbage(ft_strdup(""), 0);
	key = reg_local_garbage(dup_token_to_str(&(content->var_name), 1), 0);
	value = reg_local_garbage(dup_token_to_str(&(content->full_content), 1), 0);
	full = reg_local_garbage(ft_strjoin(key, "="), 0);
	full = ft_strjoin(full, value);
	return (full);
}

/**
 * @brief Used to put to a new execve
 * 
 * @return char** 
 */
char	**export_env_to_array(void)
{
	char			**env_virt;
	t_list			*cur;
	t_env_var_token	*content;
	int				i;

	env_virt = (char **)0;
	i = 0;
	cur = get_env_t_list();
	if (cur == (t_list *)0)
		return ((char **)0);
	env_virt = malloc(sizeof(char *) * (ft_lstsize(cur) + 1));
	if (env_virt == (char **)0)
		return ((char **)0);
	while (cur)
	{
		content = (t_env_var_token *)cur->content;
		env_virt[i] = concat_tokens(content);
		i++;
		cur = cur->next;
	}
	env_virt[i] = (char *)0;
	reg_local_garbage((void *)0, 1);
	return (env_virt);
}
