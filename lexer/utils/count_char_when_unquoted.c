/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char_when_unquoted.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:07:31 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 13:50:59 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	case_s_quote(char *str, int *i, int *counted)
{
	*i = *i + 1;
	while (str[*i])
	{
		if (is_char_single_quote(str[*i]))
			break ;
		*counted = *counted + 1;
		*i = *i + 1;
	}
}

static void	case_d_quote(char *str, int *i, int *counted)
{
	*i = *i + 1;
	while (str[*i])
	{
		if (is_char_double_quote(str[*i]))
			break ;
		*counted = *counted + 1;
		*i = *i + 1;
	}
}

int	count_char_when_unquoted(char *str)
{
	int	i;
	int	counted;

	i = 0;
	counted = 0;
	while (str[i])
	{
		if (is_char_single_quote(str[i]))
			case_s_quote(str, &i, &counted);
		else if (is_char_double_quote(str[i]))
			case_d_quote(str, &i, &counted);
		else
			counted++;
		i++;
	}
	return (counted);
}
