/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_selector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:00:02 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 22:10:08 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Ccall the right prompt if tty or not 
 * 			exit in case of malloc error
 * @return char* 
 */
char	*prompt_selector(void)
{
	char	*prompt;

	prompt = (char *)0;
	if (is_interactive_mode() == 0)
	{
		prompt = get_next_line(0, FALSE);
		if (prompt == (char *)0)
		{
			clean_exit((char *)0);
		}
		prompt[ft_strlen(prompt) - 1] = '\0';
		get_next_line(0, TRUE);
	}
	else
	{
		prompt = readline(get_display_prompt());
		if (prompt == (char *)0)
		{
			write(1, "\n", 1);
			clean_exit(prompt);
		}
	}
	return (prompt);
}
