/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_terminal_config.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:38:15 by apayet            #+#    #+#             */
/*   Updated: 2022/10/04 20:26:19 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function save the current value of the terminal inside
 * 			the struct t_data *
 */
void	save_terminal_config(void)
{
	int				ret_value;
	struct termios	*old;

	old = &(get_data((t_data *)0)->tc.old);
	ret_value = tcgetattr(0, old);
	if (ret_value == -1)
	{
		perror("Error on tcgetattr");
		clean_exit((char *)0);
	}
}
