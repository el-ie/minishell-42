/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_bonus_andif_orif.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:40:37 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:16:11 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	do_comp(char *prompt, const char *ref_comp)
{
	if (ft_strnstr(prompt, ref_comp, ft_strlen(ref_comp)) != (char *)0)
		return (1);
	return (0);
}

static int	case_quotes(char *prompt, int *i)
{
	if (is_char_single_quote(prompt[*i])
		|| is_char_double_quote(prompt[*i]))
	{
		*i += iterate_until_next_same_char_as_first(&prompt[*i]);
		return (1);
	}
	return (0);
}

int	check_validity_bonus_andif_orif(char *prompt)
{
	static const char	*ref_comp[2] = {"&&", "||"};
	int					ref_i;
	int					i;

	i = 0;
	ref_i = 0;
	while (prompt[i])
	{
		if (case_quotes(prompt, &i))
			continue ;
		if (prompt[i])
		{
			while (ref_i < 2)
			{
				if (do_comp(&prompt[i], ref_comp[ref_i]))
					return (ref_i + 1);
				ref_i++;
			}
			ref_i = 0;
		}
		i++;
	}
	return (0);
}
