/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:12:37 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 16:19:53 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	last_status_management(t_data *data)
{
	int	*wstatus;

	wstatus = &(data->status_last_cmd);
	if (WIFEXITED(*wstatus))
		*wstatus = WEXITSTATUS(*wstatus);
	else if (WIFSIGNALED(*wstatus))
		*wstatus = 128 + WTERMSIG(*wstatus);
}

int	execution(void)
{
	t_data	*data;

	data = get_data(NULL);
	if (!data->list_cmd)
		return (0);
	init_exec_struct(data->list_cmd);
	check_if_cmd_null(data->list_cmd);
	check_if_directory(data->list_cmd);
	check_if_builtin(data, data->list_cmd);
	apply_redirections_input(data->list_cmd);
	find_cmd_path_and_check_validity(data->list_cmd);
	check_if_cmd_empty(data->list_cmd);
	apply_redirections_output(data->list_cmd);
	if (add_pipes(data->list_cmd) == 0)
	{
		if (just_one_builtin(data->list_cmd))
			launch_builtin(data, data->list_cmd);
		else
			if (launch_forks(data, data->list_cmd) == 0)
				last_status_management(data);
	}
	free_exec_struct(data->list_cmd);
	return (0);
}

void	display_cmds(t_ast *ast)
{
	if (DEBUG == 0)
		return ;
	while (is_cmd(ast))
	{
		ft_printf("\n[%s]", ast->command);
		ft_printf("\nis_builtin = %d", ast->exec->is_builtin);
		ft_printf("\ncmd_validity = %d\n", ast->exec->cmd_validity);
		ft_printf("in[%d] out[%d]\n", ast->exec->in, ast->exec->out);
		ft_printf("\n---------------------------------\n");
		ast = get_next_pipe(ast);
		if (!ast)
			break ;
	}
}
