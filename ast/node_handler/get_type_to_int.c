/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:44:11 by apayet            #+#    #+#             */
/*   Updated: 2022/09/07 17:13:52 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief This function return the int value of the string type
 * 
 */
int	get_type_to_int(char *string)
{
	int					(*cmp)(const char *, const char *, size_t);
	char				*(*parse_str)(unsigned int);
	unsigned long int	(*get_len)(const char *);
	int					cursor;

	cmp = &ft_strncmp;
	parse_str = &get_type_to_string;
	get_len = &ft_strlen;
	cursor = TYPE_OPERATOR_UNDEFINED;
	while (cursor < TYPE_MAX)
	{
		if (cmp(parse_str(cursor), string, get_len(string)) == 0)
			return (cursor);
		cursor++;
	}
	return (TYPE_TOKEN_UNDEFINED);
}
