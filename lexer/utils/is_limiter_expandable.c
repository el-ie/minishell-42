/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_limiter_expandable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:05:48 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:08:24 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief This function is used inside register_heredoc
 * 
 * @param limiter 
 * @return int 
 */
int	is_limiter_expandable(char *limiter)
{
	int	i;

	i = 0;
	while (limiter[i])
	{
		if (is_char_single_quote(limiter[i])
			|| is_char_double_quote(limiter[i]))
			return (0);
		i++;
	}
	return (1);
}
