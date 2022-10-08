/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_until_next_same_char_as_first.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:41:33 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 18:46:58 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function return the step to go to same as the first char
 * 
 * @param prompt the adress at the moment for example &prompt[i]
 * @return int return the increment
 */
int	iterate_until_next_same_char_as_first(char *prompt_addr)
{
	int		i;
	char	first;

	i = 0;
	first = prompt_addr[0];
	i++;
	while (prompt_addr[i])
	{
		if (prompt_addr[i] == first)
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}
