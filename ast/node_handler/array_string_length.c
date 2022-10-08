/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_string_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:46:24 by apayet            #+#    #+#             */
/*   Updated: 2022/06/15 18:49:05 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	array_string_length(char **array)
{
	int	i;

	i = 0;
	if (array == (char **)0)
		return (i);
	while (array[i] != NULL)
		i++;
	return (i);
}
