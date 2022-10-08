/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_less_great_and.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:04:20 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 01:46:36 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	do_comp(char *prompt, const char *ref_comp)
{
	if (ref_comp == (char *)0)
		return (0);
	if (ft_strnstr(prompt, ref_comp, ft_strlen(ref_comp)) != (char *)0)
		return (1);
	return (0);
}

static void	skip_s_quote(char *prompt, int *i)
{
	*i = *i + 1;
	while (prompt[*i] && is_char_single_quote(prompt[*i]) != 1)
		*i = *i + 1;
}

static void	skip_d_quote(char *prompt, int *i)
{
	*i = *i + 1;
	while (prompt[*i] && is_char_double_quote(prompt[*i]) != 1)
		*i = *i + 1;
}

/**
 * @brief This function check if inside the prompt we have "<&" or ">&"
 * 
 * @param prompt 
 * @return int 
 */
int	check_validity_less_great_and(char *prompt)
{
	static const char	*ref_comp[5] = {"<&", ">&", "<<-", "(", ")"};
	int					ref_i;
	int					i;

	i = 0;
	ref_i = 0;
	while (prompt[i])
	{
		if (is_char_single_quote(prompt[i]))
			skip_s_quote(prompt, &i);
		if (is_char_double_quote(prompt[i]))
			skip_d_quote(prompt, &i);
		if (prompt[i])
		{
			while (ref_i < 5)
			{
				if (do_comp(&prompt[i], ref_comp[ref_i]) == 1)
					return (ref_i + 1);
				ref_i++;
			}
			ref_i = 0;
		}
		i++;
	}
	return (0);
}
