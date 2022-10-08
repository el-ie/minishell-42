/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:46:18 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 22:43:39 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	valid_argument(char *str, int i, int count, int number_presence)
{
	if (!str)
		return (0);
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] == '0')
	{
		number_presence++;
		i++;
	}
	while (str[i] && ft_is_num(str[i]))
	{
		number_presence++;
		count++;
		i++;
	}
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0' && count < 19 && number_presence)
		return (1);
	else
		return (0);
}

void	exit_without_arg(t_data *data, long long int exit_code)
{
	write(2, "exit\n", 5);
	exit_code = data->status_last_cmd;
	exit_code = exit_code % 256;
	if (exit_code >= 0)
		save_status_free_exec_clean_exit(exit_code);
	else
	{
		exit_code *= -1;
		exit_code = 256 - exit_code;
		save_status_free_exec_clean_exit(exit_code);
	}
}

void	exit_with_an_invalid_arg(char **args)
{
	write(2, "exit\n", 5);
	write(2, "exit: ", 6);
	write(2, args[0], ft_strlen(args[0]));
	write(2, ": numeric argument required\n", 28);
	save_status_free_exec_clean_exit(2);
}

void	exit_with_an_arg(char **args, long long int exit_code)
{
	write(2, "exit\n", 5);
	exit_code = ft_atol(args[0]);
	exit_code = exit_code % 256;
	if (exit_code >= 0)
		save_status_free_exec_clean_exit(exit_code);
	else
	{
		exit_code *= -1;
		exit_code = 256 - exit_code;
		save_status_free_exec_clean_exit(exit_code);
	}
}

int	builtin_exit(char **args, t_ast *ast, t_data *data)
{
	long long int	exit_code;

	if (!ast || !ast->exec)
		return (1);
	exit_code = 0;
	if (ast->exec->in_child == 1)
		get_data(NULL)->error_on_terminal_cfg = 1;
	if (!args)
		exit_without_arg(data, exit_code);
	else if (args[0] && !args[1])
	{
		if (valid_argument(args[0], 0, 0, 0))
			exit_with_an_arg(args, exit_code);
		else
			exit_with_an_invalid_arg(args);
	}
	else if (args[0] && args[1] && valid_argument(args[0], 0, 0, 0))
	{
		write(2, "exit: too many arguments\n", 25);
		get_data(NULL)->status_last_cmd = 2;
		return (424);
	}
	else
		exit_with_an_invalid_arg(args);
	return (1);
}
