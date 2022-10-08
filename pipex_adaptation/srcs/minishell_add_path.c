/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_add_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:11:38 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:09:41 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	find_cmd_path_and_check_validity(t_ast *ast)
{
	char		**paths;

	if (!ast->command || !ast->exec)
		return ;
	while (ast)
	{
		if (!ast->exec->is_builtin && !ast->exec->is_directory)
		{
			if (ast && is_cmd(ast) && ast->exec->input_redirection_validity)
			{
				paths = get_paths(ast->env);
				ast->exec->command_path = find_path(paths, ast->command, ast);
				free_paths(paths);
			}
			save_command_validity(ast);
		}
		ast = get_next_pipe(ast);
	}
}

char	*find_path(char **paths, char *cmd, t_ast *ast)
{
	t_access_test	acc;

	if (!ast)
		return (NULL);
	init_access_struct(&acc);
	if (is_path(cmd) || !paths || !paths[0])
	{
		acc.exist = access(cmd, F_OK);
		if (acc.exist == -1)
			print_not_found(cmd);
		else
		{
			acc.exec = access(cmd, X_OK);
			if (acc.exec == -1)
				print_permission_denied(cmd);
			else
				return (ft_strdup(cmd));
		}
		save_access_problem_path(ast, acc.exist, acc.exec);
	}
	else
		acc.path = get_the_path(paths, cmd, ast, -1);
	return (acc.path);
}

char	*get_the_path(char **paths, char *cmd, t_ast *ast, int i)
{
	t_access_test	acc;

	init_access_struct(&acc);
	while (paths[++i] && acc.exec != 0)
	{
		acc.path = ft_strjoin_pipex_nofree(paths[i], cmd);
		if (acc.path)
		{
			acc.exist = access(acc.path, F_OK);
			if (acc.exist == 0)
			{
				acc.exec = access(acc.path, X_OK);
				if (acc.exec == -1)
					exist_no_access(&acc.path, &acc.path_denied);
			}
		}
		if ((acc.exist == -1 || acc.exec == -1) && acc.path)
			free_path(&acc.path);
		else
			break ;
	}
	if (ft_strcmp(cmd, "#") != 0 && ft_strcmp(cmd, ":") != 0)
		ft_access_message(acc.path, acc.path_denied, cmd);
	save_access_problem_cmd(ast, acc.path, acc.path_denied);
	return (acc.path);
}
