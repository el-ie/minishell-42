/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_prompt_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:27:38 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 21:25:31 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pipe_prompt_handler(char **p_prompt)
{
	char	*prompt;

	prompt = *p_prompt;
	if (is_last_elem_is_pipe(prompt))
	{
		ft_putstr_fd("minishell : parse error near unexpected token `", 2);
		ft_putstr_fd("newline", 2);
		ft_putstr_fd("'\n", 2);
		get_data((t_data *)0)->status_last_cmd = 2;
		if (is_interactive_mode() == 0)
			clean_exit(prompt);
		return (1);
	}
	if (check_syntax_pipe(prompt))
	{
		ft_putstr_fd("minishell : parse error near unexpected token `", 2);
		ft_putstr_fd("|", 2);
		ft_putstr_fd("'\n", 2);
		get_data((t_data *)0)->status_last_cmd = 2;
		if (is_interactive_mode() == 0)
			clean_exit(prompt);
		return (1);
	}
	return (0);
}
