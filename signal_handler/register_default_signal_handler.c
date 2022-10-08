/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_default_signal_handler.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 07:06:00 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 16:22:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	register_default_signal_handler(void)
{
	t_data	*data;

	data = get_data((t_data *)0);
	if (sigaction(SIGINT, &(data->action_signal[ACT_DEFAULT]), (void *)0) < 0)
	{
		perror("sigaction");
		return (1);
	}
	if (sigaction(SIGQUIT, &(data->action_signal[ACT_DEFAULT]), (void *)0) < 0)
	{
		perror("sigaction");
		return (1);
	}
	return (0);
}
