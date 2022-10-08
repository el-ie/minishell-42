/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:45:53 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:49:58 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	display_and_free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
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

int	builtin_env(char **args, t_ast *ast, t_data *data)
{
	char	**env;

	(void)args;
	(void)data;
	if (!ast || !ast->exec)
		return (1);
	if (ast->exec->in_child == 1)
		get_data(NULL)->error_on_terminal_cfg = 1;
	env = export_env_to_array();
	if (!env)
	{
		write(2, "\nNo environment\n", 16);
		return (1);
	}
	display_and_free_env(env);
	return (0);
}
