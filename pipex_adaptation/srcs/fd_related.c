/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_related.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:53:20 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:24:41 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_standart_fd(int fd)
{
	if (fd == STDIN_FILENO || fd == STDERR_FILENO || fd == STDOUT_FILENO)
		return (1);
	return (0);
}

void	close_all_fds(t_ast *ast)
{	
	while (ast && is_cmd(ast) && ast->exec)
	{
		if (!is_standart_fd(ast->exec->in))
			close(ast->exec->in);
		if (!is_standart_fd(ast->exec->out))
			close(ast->exec->out);
		ast = get_next_pipe(ast);
	}
}

void	close_more(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	return ;
}
