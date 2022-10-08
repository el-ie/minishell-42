/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 04:33:16 by eamar             #+#    #+#             */
/*   Updated: 2022/10/04 04:34:08 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exit_save_status(int exit_code)
{
	get_data(NULL)->status_last_cmd = exit_code;
	exit(exit_code);
}

void	free_exec_clean_exit(void)
{
	t_ast	*ast;

	ast = get_data(NULL)->list_cmd;
	if (ast)
		free_exec_struct(ast);
	clean_exit((char *)0);
}

void	save_status_free_exec_clean_exit(int exit_code)
{
	t_data	*data;

	data = get_data(NULL);
	if (data)
	{
		if (data->list_cmd)
			free_exec_struct(data->list_cmd);
		data->status_last_cmd = exit_code;
	}
	clean_exit((char *)0);
}
