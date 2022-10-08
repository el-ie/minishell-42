/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:41:39 by apayet            #+#    #+#             */
/*   Updated: 2022/10/04 19:14:16 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_prompt(void)
{
	write(1, get_display_prompt(), ft_strlen(get_display_prompt()));
}

static void	rewrite_prompt(int sigstate)
{
	int	len_prompt;
	int	eraser_count;

	len_prompt = ft_strlen(get_display_prompt());
	eraser_count = 0;
	while (eraser_count < len_prompt)
	{
		write(1, "\b", 1);
		eraser_count++;
	}
	if (sigstate == STATUS_SIGINT)
		get_data((t_data *)0)->status_last_cmd = STATUS_SIGINT;
	print_prompt();
}

/**
 * @brief This is the basic action, 
 * but the prompt is not updated with right colors;
 * 
 */
static void	basic_action_interrupt(void)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

static void	signal_interruption(void)
{
	basic_action_interrupt();
	rewrite_prompt(STATUS_SIGINT);
}

/**
 * @brief 
 * 
 * @param sig 
 * @param siginfo 
 * @param context 
 */
void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)sig;
	(void)context;
	if (siginfo->si_signo == SIGINT)
		signal_interruption();
}
