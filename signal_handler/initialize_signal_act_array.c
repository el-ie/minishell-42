/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_signal_act_array.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:30:58 by apayet            #+#    #+#             */
/*   Updated: 2022/09/23 07:03:23 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	initialize_signal_act_array(void)
{
	t_data	*data;

	data = get_data((t_data *)0);
	data->action_signal[ACT_MINISHELL].sa_sigaction = &signal_handler;
	data->action_signal[ACT_MINISHELL].sa_flags = SA_SIGINFO;
	data->action_signal[ACT_HEREDOC].sa_sigaction = &heredoc_signal_handler;
	data->action_signal[ACT_HEREDOC].sa_flags = SA_SIGINFO;
	data->action_signal[ACT_IGNORE].sa_handler = SIG_IGN;
	data->action_signal[ACT_IGNORE].sa_flags = 0;
	data->action_signal[ACT_PIPE].sa_sigaction = &pipe_signal_handler;
	data->action_signal[ACT_PIPE].sa_flags = SA_SIGINFO;
	data->action_signal[ACT_DEFAULT].sa_handler = SIG_DFL;
	data->action_signal[ACT_DEFAULT].sa_flags = 0;
}
