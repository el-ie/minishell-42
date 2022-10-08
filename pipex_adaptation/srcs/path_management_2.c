/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_management_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:38:44 by eamar             #+#    #+#             */
/*   Updated: 2022/10/04 03:25:20 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_path(char **path)
{
	if (*path)
		free(*path);
	*path = 0;
}

void	exist_no_access(char **path, char **path_denied)
{
	if (*path_denied)
		free(*path_denied);
	*path_denied = ft_strdup(*path);
}

int	is_it_path(char *envp, char *str)
{
	int	i;
	int	same;

	i = 0;
	same = 0;
	while (envp[i] && str[i] && envp[i] == str[i] && i < 3)
		i++;
	if (envp[i] == str[i])
		if (envp[i + 1] < 'A' || envp[i + 1] > 'Z')
			if (envp[i + 1] < 'a' || envp[i + 1] > 'z')
				same = 1;
	return (same);
}
