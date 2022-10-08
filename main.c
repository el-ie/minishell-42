/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:04:13 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 19:28:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

/**
 * @brief
 *
 * @param prompt the prompt input
 *
 * Needd to check the lexer if return NULL
 */
static char	*do_next(char *prompt)
{
	if (lexer(prompt) == (char *)0)
	{
		free_lexer_tokens();
		return (NULL);
	}
	parser();
	free_lexer_tokens();
	return ((char *)0);
}

/**
 * @param prompt 
 * @return char* 
 */
static int	routine_readline(t_data *data, char **p_prompt)
{
	char	*prompt;

	prompt = *p_prompt;
	free_prompt(&prompt);
	if (is_interactive_mode() == 0 && data->count_line_for_heredoc_warn != 0)
		return (0);
	prompt = prompt_selector();
	data->count_line_for_heredoc_warn += 1;
	if (pipe_prompt_handler(&prompt))
		return (1);
	add_prompt_to_history(prompt, 0);
	if (check_subject_boundary(prompt) == 0)
		prompt = do_next(prompt);
	else
	{
		free_lexer_tokens();
		free_loop_main(prompt);
		return (1);
	}
	execution();
	free_loop_main(prompt);
	return (1);
}

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @param envp
 * @return int
 */
int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*prompt;
	int		loop_state;

	if (isatty(1) == 0)
		return (0);
	loading_minishell(&data, argc, argv, envp);
	loop_state = 1;
	prompt = (char *)0;
	while (loop_state)
	{
		if (is_var_exist_in_env("PATH") == 0)
			set_env_by_var_name("PATH", "");
		loop_state = routine_readline(&data, &prompt);
	}
	clean_exit(prompt);
	return (data.status_last_cmd);
}
