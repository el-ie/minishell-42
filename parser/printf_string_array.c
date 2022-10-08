/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:40:53 by apayet            #+#    #+#             */
/*   Updated: 2022/09/06 16:41:16 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_string_array(char **array)
{
	int	i;

	i = 0;
	if (array == (char **)0)
		return ;
	while (array[i])
	{
		ft_printf(" \"%s\" ", array[i]);
		i++;
	}
	write(1, "\n", 1);
}
