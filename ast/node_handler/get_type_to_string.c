/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:37:30 by apayet            #+#    #+#             */
/*   Updated: 2022/09/20 13:57:00 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
/**
 * @brief see e_token_type @brief
 * 
 * @param p_enum 
 * @return int 
 */
static int	is_e_token_type(int p_enum)
{
	return (p_enum >= TOKEN_TYPE_UNDEFINED && p_enum < TOKEN_TYPE_MAX);
}

static int	is_e_spec_op_value(int p_enum)
{
	return (p_enum >= OPERATOR_UNDEFINED && p_enum < OPERATOR_MAX_VALUE);
}

/**
 * 
 * @param string_type_int 
 * @return char* 
 */
char	*get_type_to_string(unsigned int p_enum)
{
	int	index;

	if (is_e_token_type(p_enum))
	{
		index = p_enum - 42 - 1;
		index = index + TYPE_TOKEN_UNDEFINED;
	}
	else if (is_e_spec_op_value(p_enum))
		index = p_enum;
	else
		return ((char *)0);
	return (get_data((t_data *)0)->string_type[index]);
}
