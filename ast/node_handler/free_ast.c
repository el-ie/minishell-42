/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:28:51 by apayet            #+#    #+#             */
/*   Updated: 2022/09/20 13:05:58 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_ast	*get_next_ast(t_redirect **array)
{
	int	i;

	i = 0;
	if (array == (t_redirect **)0)
		return ((t_ast *)0);
	while (array[i])
	{
		if (array[i]->type == TYPE_OPERATOR_PIPE)
			return ((t_ast *)array[i]->content);
		i++;
	}
	return ((t_ast *)0);
}

static void	free_redirect_fd_content(t_redirect **array)
{
	int				i;
	t_redirect_fd	*redirect_fd;

	i = 0;
	if (array == (t_redirect **)0)
		return ;
	while (array[i])
	{
		if (array[i]->type != TYPE_OPERATOR_PIPE)
		{
			redirect_fd = (t_redirect_fd *)array[i]->content;
			free(redirect_fd->op);
			redirect_fd->op = (char *)0;
			free(redirect_fd->filename);
			redirect_fd->filename = (char *)0;
		}
		i++;
	}
}

/**
 * @brief This function record t_redirect **
 * 
 * @param array 
 */
static void	register_t_redirect_array(t_redirect **array)
{
	int	i;

	i = 0;
	if (array == (t_redirect **)0)
		return ;
	while (array[i])
	{
		register_ast_element_to_garbage((void *)array[i], FALSE);
		register_ast_element_to_garbage((void *)array[i]->content, FALSE);
		i++;
	}
	register_ast_element_to_garbage((void *)array[i], FALSE);
	register_ast_element_to_garbage((void *)array, FALSE);
}

void	free_ast(void)
{
	t_ast	*ast;

	ast = get_data((t_data *)0)->list_cmd;
	if (ast == (t_ast *)0)
		return ;
	register_ast_element_to_garbage((void *)ast, FALSE);
	generate_envp_for_ast_tree(TRUE);
	while (ast)
	{
		ast->args = free_string_array(ast->args);
		free(ast->command);
		ast->command = (char *)0;
		free_redirect_fd_content(ast->redirects);
		register_t_redirect_array(ast->redirects);
		ast = get_next_ast(ast->redirects);
	}
	register_ast_element_to_garbage(NULL, TRUE);
	get_data((t_data *)0)->list_cmd = (t_ast *)0;
}
