/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env_var_if_exist.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:08:21 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 16:47:48 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Get the position of var in env lst object
 * 			r
 * 
 * @param key 
 * @return int -1 if not found in list;
 */
static int	get_position_of_var_in_env_lst(const char *key)
{
	int				i;
	t_list			*cur;
	t_env_var_token	*content;

	i = 0;
	if (is_var_exist_in_env(key) == 0)
		return (-1);
	cur = get_env_t_list();
	while (cur)
	{
		content = (t_env_var_token *)cur->content;
		if (do_cmp_env(key, content) == 0)
		{
			if (ft_strlen(key) == get_token_length(&(content->var_name)))
				return (i);
		}
		cur = cur->next;
		i++;
	}
	return (-1);
}

/**
 * @brief used inside unset
 * 
 * @param key 
 */
void	remove_env_var_if_exist(const char *key)
{
	t_list			*cur;
	t_list			*to_del;
	int				id;
	int				it;

	it = 0;
	id = get_position_of_var_in_env_lst(key);
	if (id == -1)
		return ;
	cur = get_env_t_list();
	if (id == 0)
	{
		get_data((t_data *)0)->list_env_token = cur->next;
		ft_lstdelone(cur, &free);
		return ;
	}
	while (it < (id - 1))
	{
		cur = cur->next;
		it++;
	}
	to_del = cur->next;
	cur->next = cur->next->next;
	ft_lstdelone(to_del, &free);
}
