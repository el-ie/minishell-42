/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_control_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:19:55 by apayet            #+#    #+#             */
/*   Updated: 2022/09/08 15:44:40 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// free at the right moment maybe a call at init minishell end close,
// depends on bonus
/**
 * @brief Get the control string object 
 * 				is eq to ";" until bonus
 * @param free 
 * @return char* 
 */
char	*get_control_string(int need_free)
{
	static char	*control = (char *)0;

	if (need_free)
	{
		free(control);
		control = (char *)0;
	}
	else
	{
		if (control == (char *)0)
			control = ft_strdup(";");
	}
	return (control);
}
