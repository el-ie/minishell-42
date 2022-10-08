/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_need_expand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:58:17 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:01:08 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Return the number of expand to do in this prompt
 * 
 * @param prompt 
 * @return int 
 */
int	prompt_need_expand(char *prompt)
{
	int	i;
	int	counted;

	i = 0;
	counted = 0;
	while (prompt[i])
	{
		if (is_char_single_quote(prompt[i]))
		{
			i++;
			while (is_char_single_quote(prompt[i]) != 1)
				i++;
		}
		if (prompt[i] == '$')
			counted++;
		i++;
	}
	return (counted);
}
