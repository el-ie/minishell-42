/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:48:48 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:23:17 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	launch_builtin(t_data *data, t_ast *ast)
{
	int	index;
	int	(*function_ptr)(char **args, t_ast *ast, t_data *data);
	int	retour;

	if (!data || !ast || !ast->exec)
		return ;
	if (!ast->exec->cmd_validity)
	{
		get_data(NULL)->status_last_cmd = 1;
		return ;
	}
	index = get_builtin_index(ast->command, data->builtin_list);
	function_ptr = data->builtin_functions[index];
	retour = (*function_ptr)(ast->args, ast, data);
	if (retour != 424)
		get_data(NULL)->status_last_cmd = retour;
	close_all_fds(data->list_cmd);
}

int	get_builtin_index(char *cmd, char *builtin_list[8])
{
	int	i;

	i = 0;
	if (!cmd || !builtin_list)
		return (7);
	while (builtin_list[i])
	{
		if (ft_strcmp(cmd, builtin_list[i]) == 0)
			return (i);
		i++;
	}
	return (7);
}

int	just_one_builtin(t_ast *ast)
{
	int	count;
	int	is_builtin;

	is_builtin = 0;
	count = 0;
	if (!ast || !ast->exec)
		return (0);
	while (ast)
	{
		if (ast->exec->is_builtin)
			is_builtin = 1;
		count++;
		ast = get_next_pipe(ast);
	}
	ast = get_data(NULL)->list_cmd;
	if (ast && count == 1 && ast->exec->is_builtin)
	{
		ast->exec->in_child = 0;
		return (1);
	}
	else
		return (0);
	(void)is_builtin;
}

void	check_if_builtin(t_data *data, t_ast *ast)
{
	int	i;

	i = 0;
	if (!data || !data->builtin_list)
		return ;
	while (ast)
	{
		while (data->builtin_list[i] && ast->command)
		{
			if (ft_strcmp(ast->command, data->builtin_list[i]) == 0)
			{
				ast->exec->is_builtin = 1;
				ast->exec->cmd_validity = 1;
			}
			i++;
		}
		i = 0;
		ast = get_next_pipe(ast);
	}
}
