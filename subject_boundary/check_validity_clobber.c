/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity_clobber.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:34:08 by apayet            #+#    #+#             */
/*   Updated: 2022/10/03 12:41:50 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	do_comp(char *prompt, const char *ref_comp)
{
	if (ft_strnstr(prompt, ref_comp, ft_strlen(ref_comp)) != (char *)0)
		return (1);
	return (0);
}

int	check_validity_clobber(char *prompt)
{
	static const char	*ref_comp = ">|";
	int					i;

	i = 0;
	while (prompt[i])
	{
		if (is_char_single_quote(prompt[i])
			|| is_char_double_quote(prompt[i]))
		{
			i += iterate_until_next_same_char_as_first(&prompt[i]);
			continue ;
		}
		if (prompt[i])
		{
			if (do_comp(&prompt[i], ref_comp))
				return (1);
		}
		i++;
	}
	return (0);
}
