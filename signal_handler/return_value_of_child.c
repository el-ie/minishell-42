/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value_of_child.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:22:17 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 16:21:29 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	return_value_of_child(int status)
{
	if ((status / CHILD_COEF) == SIGINT)
	{
		get_data((t_data *)0)->status_last_cmd = 130;
		return (0);
	}
	else if (status == 0)
	{
		get_data((t_data *)0)->status_last_cmd = 0;
		return (1);
	}
	else
	{
		if (status == 2)
			get_data((t_data *)0)->status_last_cmd = 130;
		else
			get_data((t_data *)0)->status_last_cmd = status;
		return (0);
	}
	return (1);
}
