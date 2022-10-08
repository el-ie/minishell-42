/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:37:04 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 17:36:51 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_not_found(char *cmd)
{
	int	i;

	if (!cmd)
		return ;
	i = 0;
	if (is_path(cmd))
	{
		i = ft_strlen(cmd);
		i--;
		while (cmd[i] && cmd[i] != '/')
			i--;
		i++;
	}
	if (cmd && *cmd)
		write(2, cmd + i, ft_strlen(cmd + i));
	write(2, ": command not found\n", 21);
}

void	print_permission_denied(char *path_denied)
{
	int	i;

	if (!path_denied)
		return ;
	i = 0;
	if (is_path(path_denied))
	{
		i = ft_strlen_pipex(path_denied);
		i--;
		while (path_denied[i] && path_denied[i] != '/')
			i--;
		i++;
	}
	write(2, "\n", 2);
	write(2, path_denied + i, ft_strlen_pipex(path_denied + i));
	write(2, ": permission denied\n", 21);
}
