/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ast_type_to_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:14:49 by apayet            #+#    #+#             */
/*   Updated: 2022/09/07 17:07:52 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_ast_type_to_int(char *string)
{
	int					(*cmp)(const char *, const char *, size_t);
	char				*(*parse_string)(int);
	unsigned long int	(*get_len)(const char *);

	cmp = &ft_strncmp;
	parse_string = &get_ast_type_to_string;
	get_len = &ft_strlen;
	if (cmp(parse_string(AST_TYPE_COMMAND), string, get_len(string)) == 0)
		return (AST_TYPE_COMMAND);
	if (cmp(parse_string(AST_TYPE_PIPE), string, get_len(string)) == 0)
		return (AST_TYPE_PIPE);
	return (AST_TYPE_COMMAND);
}
