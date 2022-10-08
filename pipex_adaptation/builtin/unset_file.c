/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:46:37 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:53:49 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_valid_identifier(char c, int i)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if ((c >= '0' && c <= '9') && i != 0)
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

int	valid_identifier(char *str, char *builtin_name)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_valid_identifier(str[i], i))
		{
			write(2, builtin_name, ft_strlen(builtin_name));
			write(2, ": ", 2);
			write(2, str, ft_strlen(str));
			write(2, ": not a valid identifier\n", 25);
			return (0);
		}
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	builtin_unset(char **args, t_ast *ast, t_data *data)
{
	int	i;
	int	exit_code;

	(void)data;
	if (!ast || !ast->exec)
		return (1);
	exit_code = 0;
	if (ast->exec->in_child == 1)
		get_data(NULL)->error_on_terminal_cfg = 1;
	if (!args)
		return (0);
	i = 0;
	while (args[i])
	{
		if (valid_identifier(args[i], "unset"))
			remove_env_var_if_exist(args[i]);
		else
			exit_code = 1;
		i++;
	}
	return (exit_code);
}
