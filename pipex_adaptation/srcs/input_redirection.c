/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:41:28 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 20:07:53 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	apply_redirections_input(t_ast *ast)
{
	t_redirect	*input;

	while (ast)
	{
		if (input_presence(ast))
		{
			if (input_correct_access(ast))
			{
				input = get_last_input(ast);
				input_management(input, ast);
			}
			else
			{
				ast->exec->cmd_validity = 0;
				ast->exec->input_redirection_validity = 0;
			}
		}
		ast = get_next_pipe(ast);
	}
}

void	input_management(t_redirect *input, t_ast *ast)
{
	int	fd;

	if (!ast || !input || !input->content)
		return ;
	if (input->type == OPERATOR_LESS || input->type == OPERATOR_D_LESS)
		fd = open(((t_redirect_fd *)(input->content))->filename, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		save_status_free_exec_clean_exit(1);
	ast->exec->input_redirection_presence = 1;
	ast->exec->in = fd;
}

int	test_input_access(t_redirect *input)
{	
	int			exist;
	int			read_access;
	char		*filename;

	filename = ((t_redirect_fd *)(input->content))->filename;
	exist = access(filename, F_OK);
	if (input->type == OPERATOR_D_LESS)
		return (1);
	if (exist == -1)
	{
		perror(filename);
		return (0);
	}
	read_access = access(filename, R_OK);
	if (read_access == -1)
	{
		perror(filename);
		return (0);
	}
	return (1);
}

int	input_correct_access(t_ast *ast)
{
	t_redirect	*input;
	int			accessibility;
	int			i;

	i = 0;
	if (!ast)
		return (0);
	input = get_next_input_node(ast, &i);
	while (input)
	{
		accessibility = test_input_access(input);
		if (!accessibility)
			return (0);
		input = get_next_input_node(ast, &i);
	}
	return (1);
}

int	input_presence(t_ast *ast)
{
	int	i;

	i = 0;
	if (!ast || !ast->redirects)
		return (0);
	while (ast->redirects[i] && !is_input_operator(ast->redirects[i]->type))
		i++;
	if (ast->redirects[i] != NULL)
		return (1);
	else
		return (0);
}
