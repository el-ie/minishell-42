/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_terminal_config.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:02:38 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:07:40 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	reset_terminal_config(void)
{
	struct termios	*old;
	int				checker;

	if (is_interactive_mode() == 0)
		return ;
	old = &(get_data((t_data *)0)->tc.old);
	checker = tcsetattr(0, 0, old);
	if (checker)
	{
		perror("2 error tcsetattr");
		get_data((t_data *)0)->error_on_terminal_cfg = 1;
		clean_exit((char *)0);
	}
}
