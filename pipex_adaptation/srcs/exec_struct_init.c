/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_struct_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 04:28:38 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 01:20:37 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_exec_failure(t_ast *last_ast)
{
	t_ast	*ast;

	ast = get_data(NULL)->list_cmd;
	while (ast && ast != last_ast)
	{
		free(ast->exec);
		ast = get_next_pipe(ast);
	}
	get_data(NULL)->status_last_cmd = 1;
	clean_exit((char *)0);
}

void	init_exec_struct(t_ast *ast)
{
	while (ast)
	{
		ast->exec = malloc(sizeof(t_execution));
		if (!ast->exec)
			init_exec_failure(ast);
		ast->exec->command_path = NULL;
		ast->exec->input_redirection_presence = 0;
		ast->exec->output_redirection_presence = 0;
		ast->exec->input_redirection_validity = 1;
		ast->exec->cmd_validity = 0;
		ast->exec->in = 0;
		ast->exec->out = 1;
		ast->exec->pid = 0;
		ast->exec->is_builtin = 0;
		ast->exec->is_directory = 0;
		ast->exec->exist = 1;
		ast->exec->executability = 1;
		ast->exec->in_child = 1;
		ast = get_next_pipe(ast);
	}
}

void	free_exec_struct(t_ast *ast)
{
	while (ast)
	{
		if (ast->exec)
		{
			if (ast->exec->command_path)
				free(ast->exec->command_path);
			free(ast->exec);
		}
	ast = get_next_pipe(ast);
	}
}
