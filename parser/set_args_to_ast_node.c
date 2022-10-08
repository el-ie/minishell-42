/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args_to_ast_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:32:33 by apayet            #+#    #+#             */
/*   Updated: 2022/09/03 01:33:11 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_args_to_ast_node(t_ast *ast, t_list *lst)
{
	ast->args = generate_args_array_for_ast_tree(lst);
}
