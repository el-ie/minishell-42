/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_ascii_printable.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:49:33 by apayet            #+#    #+#             */
/*   Updated: 2022/09/08 14:43:55 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_validity_ascii_printable(char *prompt)
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
		if (prompt[i] && ft_isascii(prompt[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
