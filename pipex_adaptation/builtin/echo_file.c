/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:00:52 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 20:00:54 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_if_option_n(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "-n", 2) == 0)
	{
		i = 2;
		while (str[i])
		{
			if (str[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	echo_new_line(t_ast *ast)
{
	if (!ast || !ast->exec)
		return (1);
	write(ast->exec->out, "\n", 1);
	return (0);
}

int	builtin_echo(char **args, t_ast *ast, t_data *data)
{
	int	i;
	int	option_n;

	(void)data;
	if (!ast || !ast->exec)
		return (1);
	if (ast->exec->in_child == 1)
		get_data(NULL)->error_on_terminal_cfg = 1;
	i = 0;
	if (!args || !args[0])
		return (echo_new_line(ast));
	option_n = check_if_option_n(args[0]);
	while (args[i] && check_if_option_n(args[i]))
		i++;
	while (args[i])
	{
		write(ast->exec->out, args[i], ft_strlen(args[i]));
		if (args[i + 1])
			write(ast->exec->out, " ", 1);
		i++;
	}
	if (!option_n)
		write(ast->exec->out, "\n", 1);
	return (0);
}
