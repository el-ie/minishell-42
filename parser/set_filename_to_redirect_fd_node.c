/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_filename_to_redirect_fd_node.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:51:46 by apayet            #+#    #+#             */
/*   Updated: 2022/09/08 15:44:11 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_filename_to_redirect_fd_node(t_redirect_fd *p, t_lexer_token *tok)
{
	p->filename = dup_token_to_str(tok, 1);
}
