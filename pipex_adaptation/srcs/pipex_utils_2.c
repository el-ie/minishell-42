/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:38:12 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:10:03 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_ast	*get_next_pipe(t_ast *ast)
{
	int	i;

	i = 0;
	if (!ast || !ast->redirects)
		return (NULL);
	while (ast->redirects[i])
	{
		if (ast->redirects[i]->type == OPERATOR_PIPE)
		{
			return ((t_ast *)ast->redirects[i]->content);
		}
		i++;
	}
	return (NULL);
}

int	another_pipe(t_ast *ast)
{
	int	i;

	i = 0;
	if (!ast || !ast->redirects)
	{
		return (0);
	}
	while (ast->redirects[i] != 0)
	{
		if (ast->redirects[i]->type == OPERATOR_PIPE)
			return (1);
		i++;
	}
	return (0);
}

void	save_command_validity(t_ast *ast)
{
	if (!ast || !ast->exec)
		return ;
	if (ast->exec->command_path)
		ast->exec->cmd_validity = 1;
	else
		ast->exec->cmd_validity = 0;
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	if (!paths)
		return ;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}
