/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:03:15 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 13:43:56 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Remove quote on the string and free the (char *)str from params
 * 
 * @param str 
 * @return char* 
 */
char	*remove_quotes(char *str)
{
	int		new_len;
	char	*new_limiter;

	new_len = count_char_when_unquoted(str) + 1;
	new_limiter = (char *)0;
	new_limiter = malloc(sizeof(char) * new_len);
	if (new_limiter == (char *)0)
	{
		perror("malloc error inside heredoc rm_quotes");
		return ((char *)0);
	}
	strncpy_with_quotes_rules(new_limiter, str);
	free(str);
	str = (char *)0;
	return (new_limiter);
}
