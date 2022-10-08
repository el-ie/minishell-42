/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_heredoc_signal_handler.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:47:15 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 16:19:54 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	register_heredoc_signal_handler(void)
{
	t_data	*data;

	data = get_data((t_data *)0);
	if (sigaction(SIGINT, &(data->action_signal[ACT_HEREDOC]), (void *)0) < 0)
	{
		perror("sigaction");
		return (1);
	}
	if (sigaction(SIGQUIT, &(data->action_signal[ACT_IGNORE]), (void *)0) < 0)
	{
		perror("sigaction");
		return (1);
	}
	return (0);
}
