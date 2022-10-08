/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:00:11 by eamar             #+#    #+#             */
/*   Updated: 2022/10/04 03:25:14 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	if (!envp)
		save_status_free_exec_clean_exit(1);
	while (envp[i])
	{
		if (is_it_path(envp[i], "PATH"))
			break ;
		i++;
	}
	paths = ft_split_slash(envp[i] + 5, ':', 0);
	return (paths);
}

void	save_access_problem_path(t_ast *ast, int exist, int exec)
{
	if (exist == -1)
	{
		ast->exec->exist = 0;
		return ;
	}
	if (exec == -1)
	{
		ast->exec->executability = 0;
		return ;
	}
}

void	save_access_problem_cmd(t_ast *ast, char *path, char *path_denied)
{
	if (!path && !path_denied)
		ast->exec->exist = 0;
	if (!path && path_denied)
		ast->exec->executability = 0;
	if (path_denied)
		free(path_denied);
}

void	ft_access_message(char *path, char *path_denied, char *cmd)
{
	if (!path && !path_denied)
		print_not_found(cmd);
	if (cmd[0] == '\0')
		print_not_found(cmd);
	if (!path && path_denied)
		print_permission_denied(path_denied);
}

void	init_access_struct(t_access_test *acc)
{
	acc->exist = -1;
	acc->exec = -1;
	acc->path = NULL;
	acc->path_denied = NULL;
}
