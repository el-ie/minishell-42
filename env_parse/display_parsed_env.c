/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_parsed_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:13:00 by apayet            #+#    #+#             */
/*   Updated: 2022/07/07 15:12:32 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	display_parsed_env(void)
{
	t_list	*env_list;

	env_list = (t_list *)0;
	env_list = get_data((t_data *)0)->list_env_token;
	if (env_list == (t_list *)0)
		return ;
	ft_lstiter(env_list, &display_env_var_token_fd);
}
