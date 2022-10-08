/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_terminal_config.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:49:56 by apayet            #+#    #+#             */
/*   Updated: 2022/10/04 20:26:23 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	copy_old_to_new_termios(void)
{
	struct termios	*src;
	struct termios	*dst;

	src = &(get_data((t_data *)0)->tc.old);
	dst = &(get_data((t_data *)0)->tc.new);
	ft_memcpy(dst, src, sizeof(struct termios));
}

void	set_new_terminal_config(void)
{
	struct termios	*new_cfg;
	int				checker;

	if (is_interactive_mode() == 0)
		return ;
	copy_old_to_new_termios();
	new_cfg = &(get_data((t_data *)0)->tc.new);
	new_cfg->c_lflag &= ~ECHOCTL;
	checker = tcsetattr(0, 0, new_cfg);
	if (checker)
	{
		perror("1 error tcsetattr");
		clean_exit((char *)0);
	}
}
