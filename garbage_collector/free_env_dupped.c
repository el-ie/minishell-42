/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_dupped.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:37:33 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 21:29:39 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_dupped(int need_free)
{
	t_list		*env_dup_lst;

	env_dup_lst = get_data((t_data *)0)->env_dup_list;
	if (need_free)
	{
		ft_lstclear(&env_dup_lst, &free);
		get_data((t_data *)0)->env_dup_list = (t_list *)0;
	}
}
