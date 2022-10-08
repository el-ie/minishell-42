/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:46:43 by apayet            #+#    #+#             */
/*   Updated: 2022/09/08 15:31:53 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	case_char_single_quote(int *s_enabled, int *d_enabled, int *counted)
{
	if (*s_enabled == 0)
	{
		if (*d_enabled == 0)
		{
			*counted += 1;
			*s_enabled = 1;
		}
	}
	else
	{
		if (*d_enabled == 0)
		{
			*counted += 1;
			*s_enabled = 0;
		}
	}
}

static void	case_char_double_quote(int *s_enabled, int *d_enabled, int *counted)
{
	if (*d_enabled == 0)
	{
		if (*s_enabled == 0)
		{
			*counted += 1;
			*d_enabled = 1;
		}
	}
	else
	{
		if (*s_enabled == 0)
		{
			*counted += 1;
			*d_enabled = 0;
		}
	}		
}

static int	do_return(int s_enabled, int d_enabled, int counted)
{
	if (counted % 2 == 0)
		return (0);
	if (d_enabled && s_enabled)
		return (1);
	if (d_enabled)
		return (2);
	if (s_enabled)
		return (3);
	return (0);
}

/**
 * @brief This function check if a single quote or dual quote is not alone.
 * 
 * @param prompt The string to checkj
 * @return
 */
int	check_validity_quotes(char *prompt)
{
	int	s_enabled;
	int	d_enabled;
	int	counted;
	int	i;

	i = 0;
	s_enabled = 0;
	d_enabled = 0;
	counted = 0;
	while (prompt[i])
	{
		if (is_char_single_quote(prompt[i]))
			case_char_single_quote(&s_enabled, &d_enabled, &counted);
		else if (is_char_double_quote(prompt[i]))
			case_char_double_quote(&s_enabled, &d_enabled, &counted);
		i++;
	}
	return (do_return(s_enabled, d_enabled, counted));
}
