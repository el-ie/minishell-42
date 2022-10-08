/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_var_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:50:03 by apayet            #+#    #+#             */
/*   Updated: 2022/08/09 12:58:17 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_var_token(void)
{
	t_env_var_token	*env_var;
	t_list			*main_node;

	main_node = get_data((t_data *)0)->list_env_token;
	while (main_node)
	{
		env_var = (t_env_var_token *)main_node->content;
		if (env_var->splited_content != (t_list *)0)
		{
			ft_lstclear(&(env_var->splited_content), &free);
			env_var->splited_content = (t_list *)0;
		}
		main_node = main_node->next;
	}
	ft_lstclear(&(get_data((t_data *)0)->list_env_token), &free);
	get_data((t_data *)0)->list_env_token = (t_list *)0;
}
