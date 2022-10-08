/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:20:04 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:15:53 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_output_operator(int type)
{
	if (type == OPERATOR_GREAT || type == OPERATOR_D_GREAT)
		return (1);
	return (0);
}

void	remove_text(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_TRUNC, 00644);
	write(fd, NULL, 0);
	close(fd);
}

t_redirect	*get_next_output_node(t_ast *ast, int *i)
{
	if (!ast || !ast->redirects)
		return (NULL);
	while (ast->redirects[*i] && !is_output_operator(ast->redirects[*i]->type))
		(*i)++;
	if (ast->redirects[*i] != NULL)
	{
		(*i)++;
		return (ast->redirects[(*i) - 1]);
	}
	else
		return (NULL);
}

t_redirect	*get_last_output(t_ast *ast)
{
	t_redirect	*output;
	int			i;

	output = NULL;
	i = 0;
	if (!ast || !ast->redirects)
		return (NULL);
	while (ast->redirects[i])
	{
		if (is_output_operator(ast->redirects[i]->type))
			output = ast->redirects[i];
		i++;
	}
	return (output);
}
