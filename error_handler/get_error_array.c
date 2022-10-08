/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:15:43 by apayet            #+#    #+#             */
/*   Updated: 2022/06/15 17:11:50 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Get the error array object
 * 
 * @return int** 
 */
int	**get_error_array(void)
{
	return (get_data((t_data *)0)->errors.errors_addr_array);
}
