/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy_with_quotes_rules.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:09:00 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:13:08 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	case_s_quote(char *dest, char *str, int *i, int *j)
{
	*i = *i + 1;
	while (str[*i])
	{
		if (is_char_single_quote(str[*i]))
			break ;
		dest[*j] = str[*i];
		*j = *j + 1;
		*i = *i + 1;
	}
}

static void	case_d_quote(char *dest, char *str, int *i, int *j)
{
	*i = *i + 1;
	while (str[*i])
	{
		if (is_char_double_quote(str[*i]))
			break ;
		dest[*j] = str[*i];
		*j = *j + 1;
		*i = *i + 1;
	}
}

void	strncpy_with_quotes_rules(char *dest, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_char_single_quote(str[i]))
			case_s_quote(dest, str, &i, &j);
		else if (is_char_double_quote(str[i]))
			case_d_quote(dest, str, &i, &j);
		else
		{
			dest[j] = str[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
}
