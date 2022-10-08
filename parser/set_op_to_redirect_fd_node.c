/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_op_to_redirect_fd_node.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:55:49 by apayet            #+#    #+#             */
/*   Updated: 2022/09/06 16:56:15 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_op_to_redirect_fd_node(t_redirect_fd *node, t_list *lst)
{
	node->op = dup_token_to_str((t_lexer_token *)lst->content, TRUE);
}
