/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_semicolon.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:47:36 by apayet            #+#    #+#             */
/*   Updated: 2022/08/10 10:48:06 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_validity_semicolon(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (is_char_single_quote(prompt[i]))
		{
			i++;
			while (prompt[i] && is_char_single_quote(prompt[i]) != 1)
				i++;
		}
		if (is_char_double_quote(prompt[i]))
		{
			i++;
			while (prompt[i] && is_char_double_quote(prompt[i]) != 1)
				i++;
		}
		if (prompt[i] && is_char_semicolon(prompt[i]))
			return (0);
		i++;
	}
	return (1);
}
