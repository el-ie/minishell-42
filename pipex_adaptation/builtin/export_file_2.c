/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_file_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamar <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 00:57:27 by eamar             #+#    #+#             */
/*   Updated: 2022/10/05 19:52:08 by eamar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	valid_export_argument(char *str)
{
	int	i;
	int	equal_presence;

	if (!str)
		return (0);
	i = 0;
	equal_presence = 0;
	while (str[i])
	{
		if (str[i] == '=')
			equal_presence = 1;
		i++;
	}
	i = 0;
	if (!equal_presence)
		return (0);
	return (1);
}

void	free_key_and_value(char **key, char **value)
{
	if (key && *key)
	{
		free(*key);
		*key = 0;
	}
	if (value && *value)
	{
		free(*value);
		*value = 0;
	}
}
