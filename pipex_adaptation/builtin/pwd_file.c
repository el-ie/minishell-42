/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 00:27:42 by eamar             #+#    #+#             */
/*   Updated: 2022/10/06 00:00:28 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_pwd(char **args, t_ast *ast, t_data *data)
{
	char	path[PATH_MAX];

	(void)args;
	(void)data;
	if (!ast || !ast->exec)
		return (1);
	if (ast->exec->in_child == 1)
		get_data(NULL)->error_on_terminal_cfg = 1;
	if (getcwd(path, PATH_MAX))
	{
		write(1, path, ft_strlen(path));
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		perror("pwd");
		return (1);
	}
}
