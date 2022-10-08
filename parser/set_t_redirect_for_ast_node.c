/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_redirect_for_ast_node.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:38:03 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 12:44:48 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_t_redirect_for_ast_node(t_ast *ast, t_list *lst)
{
	ast->redirects = generate_t_redirect_for_ast_tree(lst);
}
