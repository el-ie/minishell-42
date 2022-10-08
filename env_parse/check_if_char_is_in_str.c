/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_char_is_in_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:19:34 by apayet            #+#    #+#             */
/*   Updated: 2022/07/07 18:15:01 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_if_char_is_in_str(const char *str, char c)
{
	int	i;
	int	founded;

	i = 0;
	founded = 0;
	while (str[i])
	{
		if (str[i] == c)
			founded = 1;
		if (founded == 1)
			break ;
		i++;
	}
	if (founded == 1)
		return (1);
	return (0);
}
