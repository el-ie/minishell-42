/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:33:29 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 02:05:57 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	child_process_hdoc(void)
{
	register_heredoc_signal_handler();
	request_prompt_heredoc_from_list();
}

static int	parent_process_signal(int pid)
{
	t_sigaction	*act;

	act = &(get_data((t_data *)0)->action_signal[ACT_IGNORE]);
	if (pid != 0)
	{
		if (sigaction(SIGINT, act, (void *)0) < 0)
		{
			perror("sigaction");
			return (0);
		}
	}
	return (1);
}

/**
 * @brief When we use the command, we cannot interrupt the readline instance 
 * 			so call inside fork and if SIGINT, we exit the fork so we exit the 
 * 			readline function
 * 
 * 	@return a boolean representation for continue or not the execution
 * 
 */
static int	fork_heredoc_prompter(void)
{
	int	pid;
	int	status;
	int	(*prev_count_line)(void);

	prev_count_line = &get_previous_counted_line_from_file;
	pid = fork();
	if (pid < 0)
	{
		perror("fork heredoc erro :");
		clean_exit(NULL);
	}
	if (parent_process_signal(pid) == 0)
		return (0);
	if (pid == 0)
		child_process_hdoc();
	waitpid(pid, &status, 0);
	get_data((t_data *)0)->count_line_for_heredoc_warn = prev_count_line();
	remove_counted_line(".tmp_counted_line");
	register_signal_handler();
	return (return_value_of_child(status));
}

/**
 * @brief This is a function wrapper for the heredoc
 * 
 * @return int return false if an error, for example syntax error
 */
int	main_heredoc(void)
{
	if (is_heredoc_having_limiter() == 0)
		return (0);
	get_data((t_data *)0)->status_last_cmd = 0;
	set_token_type_for_heredoc_limiter();
	register_heredoc();
	if (fork_heredoc_prompter() == 0)
		return (0);
	return (1);
}
