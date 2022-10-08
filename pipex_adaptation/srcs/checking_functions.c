/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 04:29:53 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:11:16 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	check_if_cmd_null(t_ast *ast)
{
	while (ast)
	{
		if (!ast->command)
			ast->exec->cmd_validity = 0;
		ast = get_next_pipe(ast);
	}
}

void	check_if_cmd_empty(t_ast *ast)
{
	if (!ast || !ast->command)
		return ;
	while (ast)
	{
		if (ast->command && ast->command[0] == '\0')
			ast->exec->cmd_validity = 0;
		ast = get_next_pipe(ast);
	}
}

void	check_if_directory(t_ast *ast)
{
	int			retour;
	struct stat	*buf;

	buf = malloc(sizeof(struct stat));
	if (!buf)
		save_status_free_exec_clean_exit(1);
	while (ast)
	{
		if (ast->command)
		{
			retour = stat(ast->command, buf);
			if (retour == 0 && S_ISDIR(buf->st_mode))
			{
				write(2, ast->command, ft_strlen(ast->command));
				write(2, ": Is a directory\n", 17);
				ast->exec->is_directory = 1;
			}
		}
		ast = get_next_pipe(ast);
	}
	if (buf)
		free(buf);
}
