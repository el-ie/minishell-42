/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:01:12 by apayet            #+#    #+#             */
/*   Updated: 2022/06/15 17:14:33 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Set the errors addr array object
 * 	This function set the adresse of each value from t_error_state inside 
 * 	the arrays of pointer : errors_addr_array\
 * 	
 * 	With thios just to itterate inside this array for checking error 
 * 
 */
static void	set_errors_addr_array(void)
{
	t_error_state	*errors;
	int				**errors_array;

	errors = &(get_data((t_data *)0)->errors);
	errors_array = get_error_array();
	errors_array[CREATE_NODE_ERROR] = &(errors->create_node);
	errors_array[PARSE_SIMPLE_COMMAND_ERROR] = &(errors->parse_simple_commad);
	errors_array[TYPE_TO_STRING_ERROR] = &(errors->to_string_type_error);
	errors_array[MALLOC_ERROR] = &(errors->malloc_error);
}

/**
 * @brief This function return a value
 * 			if equals to 0 || NO_ERROR
 * 			if equals to 1 || ERROR
 * 
 * @return int 
 */
int	is_error(void)
{
	static int	errors_addr_array_setted = 0;
	int			**array;
	int			i;

	i = 0;
	if (errors_addr_array_setted == 0)
	{
		set_errors_addr_array();
		errors_addr_array_setted = 1;
	}
	array = get_error_array();
	while (i < MAXIMUM_ERROR)
	{
		if (*array[i] != 0)
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}
