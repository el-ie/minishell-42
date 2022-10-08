/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ast_type_string_to_ast_node.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:31:07 by apayet            #+#    #+#             */
/*   Updated: 2022/09/02 22:31:41 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// no need to free init on minishell inside global garbage
void	set_ast_type_string_to_ast_node(t_ast *ast, int ast_type)
{
	ast->type = get_ast_type_to_string(ast_type);
}
