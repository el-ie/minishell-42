/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:44:36 by apayet            #+#    #+#             */
/*   Updated: 2022/09/22 16:45:43 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_env_var_token	*create_token(t_env_var_token **p_content, int founded)
{
	t_env_var_token	*content;

	content = *p_content;
	if (founded == 0)
	{
		content = malloc(sizeof(t_env_var_token));
		if (content == (t_env_var_token *)0)
		{
			set_error_state(MALLOC_ERROR);
			return (content);
		}
	}
	return (content);
}

/**
 * @brief Used inside set_env_by_var_name function
 * 
 * @param p_c 
 * @param f_key 
 * @param key 
 * @param value 
 */
void	set_up_content(void **p_c, int f_key, char *key, char *value)
{
	t_env_var_token	*cont;
	size_t			len;

	len = 0;
	cont = (t_env_var_token *)*p_c;
	cont = create_token(&cont, f_key);
	cont->var_name.start_address = ft_strdup_arc(key);
	len = ft_strlen(key);
	cont->var_name.end_address = cont->var_name.start_address + len;
	cont->var_name.length = len;
	cont->full_content.start_address = ft_strdup_arc(value);
	len = ft_strlen(value);
	cont->full_content.end_address = cont->full_content.start_address + len;
	cont->full_content.length = ft_strlen(value);
}
