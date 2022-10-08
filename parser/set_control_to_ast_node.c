/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_control_to_ast_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:22:17 by apayet            #+#    #+#             */
/*   Updated: 2022/09/02 22:25:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_control_to_ast_node(t_ast *ast)
{
	ast->control = get_control_string(FALSE);
}
