/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:23:52 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 23:42:07 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	cd_without_arg_next(char *cur_pwd)
{
	if (cur_pwd)
	{
		set_env_by_var_name("OLDPWD", cur_pwd);
		free(cur_pwd);
	}
	cur_pwd = getcwd(NULL, 0);
	if (cur_pwd)
	{
		set_env_by_var_name("PWD", cur_pwd);
		free(cur_pwd);
	}
}

static int	cd_without_arg(char *cur_pwd, char *home, int retour)
{
	cur_pwd = getcwd(NULL, 0);
	if (is_var_exist_in_env("HOME") == 0)
	{
		write(2, "cd: HOME not set\n", 17);
		free(cur_pwd);
		return (1);
	}
	home = get_env_value("HOME");
	retour = chdir(home);
	if (retour == -1)
	{
		free(cur_pwd);
		perror("cd");
		return (1);
	}
	else
	{
		cd_without_arg_next(cur_pwd);
		return (0);
	}
}

static void	cd_with_an_arg_next(char *cur_pwd)
{
	if (cur_pwd)
	{
		set_env_by_var_name("OLDPWD", cur_pwd);
		free(cur_pwd);
	}
	cur_pwd = getcwd(NULL, 0);
	if (cur_pwd)
	{
		set_env_by_var_name("PWD", cur_pwd);
		free(cur_pwd);
	}
}

static int	cd_with_an_arg(char **args, char *cur_pwd, int retour)
{
	cur_pwd = getcwd(NULL, 0);
	if (!cur_pwd)
	{
		perror("");
		return (1);
	}
	retour = chdir(args[0]);
	if (retour == -1)
	{
		free(cur_pwd);
		perror(args[0]);
		return (1);
	}
	else
	{
		cd_with_an_arg_next(cur_pwd);
		return (0);
	}
}

int	builtin_cd(char **args, t_ast *ast, t_data *data)
{
	int		retour;
	char	*cur_pwd;
	char	*home;

	(void)data;
	if (!ast || !ast->exec)
		return (1);
	if (ast->exec->in_child == 1)
		get_data(NULL)->error_on_terminal_cfg = 1;
	cur_pwd = NULL;
	home = NULL;
	retour = 1;
	if (!args)
		return (cd_without_arg(cur_pwd, home, retour));
	if (args[0] && args[1])
	{
		write(2, "cd: too many arguments\n", 23);
		return (1);
	}
	if (args[0])
		return (cd_with_an_arg(args, cur_pwd, retour));
	return (1);
}
