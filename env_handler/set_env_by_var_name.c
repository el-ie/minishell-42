/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_by_var_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:51:05 by apayet            #+#    #+#             */
/*   Updated: 2022/10/06 02:20:03 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	env_is_malloced(t_env_var_token **p_content, int *sub_tokenized)
{
	t_env_var_token	*cont;
	int				(*count)(const char *, char);

	cont = *p_content;
	count = &count_until_char_found;
	*sub_tokenized = count(cont->full_content.start_address, ':');
	cont->full_content.start_address = (char *)0;
}

static int	perfect_match(void *p_c, char *key, int *f_key, int *sub)
{
	t_env_var_token	*content;

	content = (t_env_var_token *)p_c;
	if (is_cmp_perfect_match(ft_strlen(key), content))
	{
		if (is_env_token_malloced(key))
			env_is_malloced(&content, sub);
		*f_key = 1;
	}
	return (*f_key);
}

/**
 * @brief Create a new env var if it doesn't exist
 * 				TO-DO : no armor on allowed char is setted now
 * @param key 
 * @param value 
 */
static int	create_new_env_var(const char *key, const char *value)
{
	t_env_var_token	*m_new;

	if (is_var_exist_in_env(key) == 1)
		return (0);
	m_new = (t_env_var_token *)create_node(NODE_TYPE_ENV_VAR_TOKEN);
	new_env_var_lex_token(key, &(m_new->var_name));
	new_env_var_lex_token(value, &(m_new->full_content));
	ft_lstadd_back(get_env_t_list_addr(), ft_lstnew((void *)m_new));
	return (1);
}

/**
 * @brief Set the env by var name object
 * 
 * @param key 
 * @param value 
 */
void	set_env_by_var_name(const char *key, const char *value)
{
	t_list			*cur;
	t_env_var_token	*content;
	size_t			key_length;
	int				f_key;
	int				sub;

	cur = get_env_t_list();
	if (cur == (t_list *)0 || create_new_env_var(key, value) == 1)
		return ;
	init_vars(&key_length, &f_key, &sub, key);
	while (cur)
	{
		content = (t_env_var_token *)cur->content;
		if (do_cmp_env(key, content) == 0)
		{
			if (perfect_match((void *)content, (char *)key, &f_key, &sub) == 1)
				break ;
		}
		cur = cur->next;
	}
	set_up_content((void **)&content, f_key, (char *)key, (char *)value);
	if (f_key == 0)
		ft_lstadd_back(get_env_t_list_addr(), ft_lstnew((void *)content));
}
