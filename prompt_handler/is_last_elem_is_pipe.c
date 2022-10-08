/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_last_elem_is_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:33:51 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:41:37 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This will triger another prompt
 * 
 * @param prompt 
 * @return int 
 */
int	is_last_elem_is_pipe(char *prompt)
{
	int	i;

	i = ft_strlen(prompt) - 1;
	while (i > -1)
	{
		if (prompt[i] == ' ' || prompt[i] == '\t')
		{
			i--;
			continue ;
		}
		else if (prompt[i] == '|')
			return (1);
		else
			return (0);
		i--;
	}
	return (0);
}
