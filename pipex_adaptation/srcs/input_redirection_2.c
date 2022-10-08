/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:33:41 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 18:55:02 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redirect	*get_next_input_node(t_ast *ast, int *i)
{
	if (!ast || !ast->redirects)
		return (NULL);
	while (ast->redirects[*i] && !is_input_operator(ast->redirects[*i]->type))
		(*i)++;
	if (ast->redirects[*i] != NULL)
	{
		(*i)++;
		return (ast->redirects[(*i) - 1]);
	}
	else
		return (NULL);
}

t_redirect	*get_last_input(t_ast *ast)
{
	t_redirect	*input;
	int			i;

	input = NULL;
	i = 0;
	if (!ast || !ast->redirects)
		return (NULL);
	while (ast->redirects[i])
	{
		if (is_input_operator(ast->redirects[i]->type))
			input = ast->redirects[i];
		i++;
	}
	return (input);
}

int	is_input_operator(int type)
{
	if (type == OPERATOR_LESS || type == OPERATOR_D_LESS)
		return (1);
	else
		return (0);
}
