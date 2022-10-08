/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:43:15 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:26:55 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	launch_forks(t_data *data, t_ast *list_cmd)
{
	pid_t	pid;
	t_ast	*ast;

	ast = list_cmd;
	ignore_signal_handler();
	while (ast && is_cmd(ast))
	{
		pid = fork();
		if (pid == -1)
		{
			fork_failure(data, ast);
			return (1);
		}
		if (pid == 0)
		{
			register_default_signal_handler();
			launch_exec(ast, list_cmd, data);
		}
		ast->exec->pid = pid;
		ast = get_next_pipe(ast);
	}
	close_all_fds(list_cmd);
	wait_processes_save_status(data);
	register_signal_handler();
	return (0);
}

void	launch_exec(t_ast *ast, t_ast *list_cmd, t_data *data)
{
	if (!data)
		exit(1);
	if (!ast || !ast->exec)
		save_status_free_exec_clean_exit(1);
	if (ast->exec->cmd_validity)
		launch_exec_valid_cmd(ast, list_cmd, data);
	else
	{
		close_all_fds(list_cmd);
		close_more();
		if (!ast->exec->exist)
			save_status_free_exec_clean_exit(127);
		else if (!ast->exec->executability || ast->exec->is_directory)
			save_status_free_exec_clean_exit(126);
		else
			save_status_free_exec_clean_exit(1);
	}
}

void	launch_exec_valid_cmd(t_ast *ast, t_ast *list_cmd, t_data *data)
{
	char	**args_for_execve;

	if (ast->exec->in != STDIN_FILENO)
		ft_dup2(ast->exec->in, STDIN_FILENO);
	if (ast->exec->out != STDOUT_FILENO)
		ft_dup2(ast->exec->out, STDOUT_FILENO);
	if (ast->exec->is_builtin)
	{
		get_data(NULL)->status_last_cmd = 0;
		launch_builtin(data, ast);
		close_all_fds(list_cmd);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		free_exec_clean_exit();
	}
	else
	{
		args_for_execve = cmd_and_args(ast);
		close_all_fds(list_cmd);
		execve(ast->exec->command_path, args_for_execve, ast->env);
		perror("Error execve");
		close_more();
		free(args_for_execve);
		save_status_free_exec_clean_exit(1);
	}
}

void	wait_processes_save_status(t_data *data)
{
	int		wstatus;
	t_ast	*ast;

	ast = data->list_cmd;
	while (is_cmd(ast))
	{
		wstatus = 0;
		if (ast->exec->pid)
			waitpid(ast->exec->pid, &wstatus, 0);
		ast = get_next_pipe(ast);
		if (!ast)
			break ;
	}
	get_data(NULL)->status_last_cmd = wstatus;
}

void	fork_failure(t_data *data, t_ast *last_ast)
{	
	t_ast	*ast;
	int		wstatus;

	ast = data->list_cmd;
	while (is_cmd(ast) && ast != last_ast)
	{
		wstatus = 0;
		if (ast->exec->pid)
			waitpid(ast->exec->pid, &wstatus, 0);
		ast = get_next_pipe(ast);
		if (!ast)
			break ;
	}
	get_data(NULL)->status_last_cmd = 1;
	close_all_fds(data->list_cmd);
	register_signal_handler();
}
