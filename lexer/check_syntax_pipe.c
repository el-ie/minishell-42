/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:56:26 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 19:53:05 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	iterate_until_not_space_char(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i] && ft_is_space(prompt[i]))
		i++;
	return (i);
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

static int	case_pipe_triggered(char *prompt, int *i, int *word_b)
{
	if (*word_b == 0)
		return (1);
	else
		*word_b = 0;
	if (prompt[*i])
	{
		*i += 1;
		*i += iterate_until_not_space_char(&prompt[*i]);
		if (prompt[*i] == '|')
			return (1);
	}
	return (0);
}

int	check_syntax_pipe(char *prompt)
{
	int	i;
	int	word_before;

	i = 0;
	word_before = 0;
	i = iterate_until_not_space_char(prompt);
	while (prompt[i])
	{
		if (case_quotes(prompt, &i))
			continue ;
		if (prompt[i] == '|')
			return (case_pipe_triggered(prompt, &i, &word_before));
		if (prompt[i] && prompt[i] != '|')
			word_before = 1;
		if (prompt[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
