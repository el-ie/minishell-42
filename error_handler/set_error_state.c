/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:57:26 by apayet            #+#    #+#             */
/*   Updated: 2022/06/15 17:13:45 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Set the error state object
 * 			When a error occur this function is call with the right enum 
 * 			=> typedef enum e_error
 * 
 * @param enum_error 
 * @return t_error_state* 
 */
t_error_state	*set_error_state(unsigned int enum_error)
{
	if (enum_error >= MAXIMUM_ERROR)
		return (&(get_data((t_data *)0)->errors));
	if (CREATE_NODE_ERROR == enum_error)
		*(get_error_array())[CREATE_NODE_ERROR] = ERROR;
	if (PARSE_SIMPLE_COMMAND_ERROR == enum_error)
		*(get_error_array())[PARSE_SIMPLE_COMMAND_ERROR] = ERROR;
	if (TYPE_TO_STRING_ERROR == enum_error)
		*(get_error_array())[TYPE_TO_STRING_ERROR] = ERROR;
	if (MALLOC_ERROR == enum_error)
		*(get_error_array())[MALLOC_ERROR] = ERROR;
	return (&(get_data((t_data *)0)->errors));
}
