/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tty_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:27:46 by apayet            #+#    #+#             */
/*   Updated: 2022/10/03 16:17:39 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_tty_mode(void)
{
	t_data	*data;

	data = get_data((t_data *)0);
	if (isatty(0) == 0)
		data->is_tty_mode = 0;
	else
		data->is_tty_mode = 1;
}
