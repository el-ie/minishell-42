/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:47:25 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:18:11 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	add_pipes(t_ast *ast)
{
	int	gate[2];

	if (!ast || !ast->exec)
		return (1);
	if (!ast->exec->input_redirection_presence)
		ast->exec->in = STDIN_FILENO;
	while (ast && is_cmd(ast) && another_pipe(ast))
	{
		if (pipe(gate) == -1)
			return (pipe_error(ast));
		if (ast->exec->output_redirection_presence)
			close(gate[1]);
		else
			ast->exec->out = gate[1];
		ast = get_next_pipe(ast);
		if (ast->exec->input_redirection_presence)
			close(gate[0]);
		else
			ast->exec->in = gate[0];
	}
	if (!ast->exec->output_redirection_presence)
		ast->exec->out = STDOUT_FILENO;
	return (0);
}

int	pipe_error(t_ast *last_ast)
{
	t_ast	*ast;

	ast = get_data(NULL)->list_cmd;
	while (ast && ast != last_ast)
	{
		if (!is_standart_fd(ast->exec->in))
			close(ast->exec->in);
		if (!is_standart_fd(ast->exec->out))
			close(ast->exec->out);
		ast = get_next_pipe(ast);
	}
	write(2, "Too many requests for available file descriptors\n", 49);
	get_data(NULL)->status_last_cmd = 1;
	return (1);
}
