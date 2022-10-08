/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_prompt_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:31:46 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 18:34:33 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief When readline is empty just continue a
 * 			new loop for getting a new readline
 *
 * @param prompt
 * @return int
 */
int	is_prompt_empty(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i]
		&& (prompt[i] == ' ' || prompt[i] == '\t'))
		i++;
	if (prompt[i] == '\0')
		return (1);
	return (0);
}
