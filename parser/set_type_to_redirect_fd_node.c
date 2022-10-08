/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type_to_redirect_fd_node.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:54:18 by apayet            #+#    #+#             */
/*   Updated: 2022/09/06 16:55:05 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_type_to_redirect_fd_node(t_redirect_fd *node, int op_type)
{
	node->type = op_type;
}
