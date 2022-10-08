/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:24:14 by apayet            #+#    #+#             */
/*   Updated: 2022/07/07 16:46:15 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Get the data object
 * 			For the  first usage init with the adress of t_data
 * 			from the main
 * 
 * 		After the initialisation you need to use it with the NULL params 
 * 
 * @param p_data  insert null for get the data 
 * 					|| insert the adress of data to set
 * @return t_data* 
 */
t_data	*get_data(t_data *p_data)
{
	static t_data	*data = (t_data *)0;

	if (p_data != (t_data *)0)
		data = p_data;
	return (data);
}
