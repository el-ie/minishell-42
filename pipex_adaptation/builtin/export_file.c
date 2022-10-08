/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:46:26 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:52:57 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*extract_key(char *str)
{
	char	*key;
	int		i;

	i = 0;
	key = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!key)
		save_status_free_exec_clean_exit(1);
	while (str[i] && str[i] != '=')
	{
		key[i] = str[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

static char	*extract_value(char *str)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	value = malloc(sizeof(char) * ft_strlen(str));
	if (!value)
		save_status_free_exec_clean_exit(1);
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] && str[i] == '=')
		i++;
	while (str[i])
	{
		value[j] = str[i];
		i++;
		j++;
	}
	value[j] = '\0';
	return (value);
}

void	export_without_args(void)
{
	int		i;
	char	**env;

	env = export_env_to_array();
	if (!env)
	{
		write(2, "\nNo environment\n", 16);
		return ;
	}
	i = 0;
	while (env[i])
	{
		write(1, "export ", 7);
		write(1, env[i], ft_strlen(env[i]));
		write(1, "\n", 1);
		i++;
	}
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

void	export_with_args(char **args, int *exit_code, char *key, char *value)
{
	int	i;

	i = 0;
	while (args[i])
	{	
		key = extract_key(args[i]);
		if (valid_identifier(key, "export") && valid_export_argument(args[i]))
		{
			value = extract_value(args[i]);
			if (!value)
				value = ft_strdup("\0");
			if (key)
			{
				set_env_by_var_name(key, value);
				free(key);
				key = NULL;
			}
		}
		else
			*exit_code = 1;
		free_key_and_value(&key, &value);
		i++;
	}
}

int	builtin_export(char **args, t_ast *ast, t_data *data)
{
	char	*key;
	char	*value;
	int		exit_code;

	(void)data;
	if (!ast || !ast->exec)
		return (1);
	exit_code = 0;
	key = NULL;
	value = NULL;
	if (ast->exec->in_child == 1)
		get_data(NULL)->error_on_terminal_cfg = 1;
	if (!args)
	{
		export_without_args();
		return (0);
	}
	else
		export_with_args(args, &exit_code, key, value);
	return (exit_code);
}
