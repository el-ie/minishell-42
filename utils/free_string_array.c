/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_string_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:14:19 by apayet            #+#    #+#             */
/*   Updated: 2022/09/29 16:14:53 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**free_string_array(char **array)
{
	int	i;

	i = 0;
	if (array == (char **)0)
		return ((char **)0);
	while (array[i])
	{
		free(array[i]);
		array[i] = (char *)0;
		i++;
	}
	return (array);
}
