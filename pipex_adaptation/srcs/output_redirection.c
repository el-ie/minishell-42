/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 00:05:27 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:16:58 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	output_management(t_redirect *output, t_ast *ast)
{
	int		fd;
	char	*filename;

	if (!output || !output->content || !ast || !ast->exec)
		return ;
	filename = ((t_redirect_fd *)(output->content))->filename;
	if (output->type == OPERATOR_GREAT)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	else if (output->type == OPERATOR_D_GREAT)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 00644);
	if (fd < 0 || write(fd, NULL, 0) == -1)
		perror(filename);
	else
	{
		ast->exec->output_redirection_presence = 1;
		ast->exec->out = fd;
	}
}

int	output_presence(t_ast *ast)
{
	int	i;

	i = 0;
	if (!ast || !ast->redirects)
		return (0);
	while (ast->redirects[i] && !is_output_operator(ast->redirects[i]->type))
		i++;
	if (ast->redirects[i])
		return (1);
	return (0);
}

int	test_output_access(t_redirect_fd *redirect)
{	
	int		exist;
	int		write_access;
	int		fd;

	exist = access(redirect->filename, F_OK);
	if (exist == -1)
	{
		fd = open(redirect->filename, O_CREAT, 00644);
		close(fd);
		return (1);
	}
	else
	{
		write_access = access(redirect->filename, W_OK);
		if (write_access == 0)
		{
			if (redirect->type == OPERATOR_GREAT)
				remove_text(redirect->filename);
			return (1);
		}
		else if (write_access == -1)
			perror(redirect->filename);
		return (0);
	}
}

int	test_access_and_create_files(t_ast *ast)
{
	t_redirect	*output;
	int			accessibility;
	int			i;

	i = 0;
	if (!ast)
		return (0);
	output = get_next_output_node(ast, &i);
	while (output && output->content)
	{
		accessibility = test_output_access((t_redirect_fd *)(output->content));
		if (!accessibility)
			return (0);
		output = get_next_output_node(ast, &i);
	}
	return (1);
}

void	apply_redirections_output(t_ast *ast)
{
	t_redirect	*output;

	while (ast)
	{
		if (output_presence(ast) && ast->exec->input_redirection_validity)
		{
			if (test_access_and_create_files(ast))
			{
				output = get_last_output(ast);
				output_management(output, ast);
			}
			else
				ast->exec->cmd_validity = 0;
		}
		ast = get_next_pipe(ast);
	}
}
