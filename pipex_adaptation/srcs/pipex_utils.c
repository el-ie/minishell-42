/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:36:52 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 18:33:13 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_dup2(int fd1, int fd2)
{
	t_data	*data;
	int		retour;

	data = get_data(NULL);
	retour = dup2(fd1, fd2);
	if (retour == -1)
	{
		close_all_fds(data->list_cmd);
		close_more();
		save_status_free_exec_clean_exit(1);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_path(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '/')
			return (1);
	return (0);
}

int	is_cmd(t_ast *ast)
{
	if (!ast || !ast->type)
		return (0);
	if (same(ast->type, "command"))
		return (1);
	return (0);
}

int	same(char *s1, char *s2)
{
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}
