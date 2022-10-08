/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_redirect_element_to_array.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:57:27 by apayet            #+#    #+#             */
/*   Updated: 2022/09/06 16:58:11 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_t_redirect_element_to_array(t_redirect **array, int len)
{
	int	i;

	if (len == 0)
		return ;
	i = 0;
	while (i < len)
	{
		array[i] = create_node(NODE_TYPE_T_REDIRECT);
		i++;
	}
	array[i] = (t_redirect *)0;
}
