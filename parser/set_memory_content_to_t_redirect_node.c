/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_memory_content_to_t_redirect_node.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:40 by apayet            #+#    #+#             */
/*   Updated: 2022/09/19 14:55:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_memory_content_to_t_redirect_node(t_redirect *node)
{
	if (node->type == OPERATOR_PIPE)
	{
		node->content = create_node(NODE_TYPE_COMMAND);
	}
	else
		node->content = create_node(NODE_TYPE_REDIRECT_FD);
}
