/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_command_to_ast_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:24:36 by apayet            #+#    #+#             */
/*   Updated: 2022/09/03 17:25:40 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_command_to_ast_node(t_ast *ast, t_list *lst)
{
	ast->command = get_command_for_ast_tree(lst);
}
