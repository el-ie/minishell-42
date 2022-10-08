/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_to_ast_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:16:52 by apayet            #+#    #+#             */
/*   Updated: 2022/09/06 18:13:31 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Set the env to ast node object
 * 
 * @param ast 
 */
void	set_env_to_ast_node(t_ast *ast)
{
	ast->env = generate_envp_for_ast_tree(FALSE);
}
