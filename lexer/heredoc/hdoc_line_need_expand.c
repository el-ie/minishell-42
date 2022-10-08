/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdoc_line_need_expand.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:48:20 by apayet            #+#    #+#             */
/*   Updated: 2022/08/30 15:48:52 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Compute if heredoc line need expand and return the number of expands 
 * 
 * @param content 
 * @return int 
 */
int	hdoc_line_need_expand(char *content)
{
	int	i;
	int	counted;

	i = 0;
	counted = 0;
	while (content[i])
	{
		if (content[i] == '$')
			counted++;
		i++;
	}
	return (counted);
}
