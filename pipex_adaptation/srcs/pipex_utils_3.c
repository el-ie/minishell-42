/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 03:57:57 by eamar             #+#    #+#             */
/*   Updated: 2022/10/04 03:58:54 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**cmd_and_args(t_ast *ast)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (ast->args)
		while (ast->args[i])
			i++;
	res = malloc(sizeof(char *) * (i + 2));
	if (!res)
		save_status_free_exec_clean_exit(1);
	i = 0;
	res[0] = ast->command;
	if (ast->args)
	{
		while (ast->args[i])
		{
			res[j] = ast->args[i];
			i++;
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
