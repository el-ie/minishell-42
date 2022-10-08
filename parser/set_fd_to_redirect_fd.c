/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd_to_redirect_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:50:26 by apayet            #+#    #+#             */
/*   Updated: 2022/09/06 16:50:56 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_fd_to_redirect_fd(t_redirect_fd *node)
{
	if (node->type == OPERATOR_GREAT || node->type == OPERATOR_D_GREAT)
		node->fd = 1;
	else if (node->type == OPERATOR_LESS || node->type == OPERATOR_D_LESS)
		node->fd = 0;
	else
		node->fd = -1;
}
