/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_string_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:34:49 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:34:50 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	check_dup_str(void)
{
	int		cursor;
	t_data	*data;

	cursor = 0;
	data = get_data((t_data *)0);
	while (cursor < TYPE_MAX)
	{
		check_malloc_fails_safe_exit((void *)data->string_type[cursor]);
		cursor++;
	}
}

void	set_string_type(void)
{
	char	*(*dup_arc)(const char *);
	t_data	*d;

	dup_arc = &ft_strdup_arc;
	d = get_data((t_data *)0);
	d->string_type[TYPE_OPERATOR_UNDEFINED] = dup_arc("operator undefined");
	d->string_type[TYPE_OPERATOR_PIPE] = dup_arc("operator pipe");
	d->string_type[TYPE_OPERATOR_D_GREAT] = dup_arc("operator d_great");
	d->string_type[TYPE_OPERATOR_D_LESS] = dup_arc("operator d_less");
	d->string_type[TYPE_OPERATOR_GREAT] = dup_arc("operator great");
	d->string_type[TYPE_OPERATOR_LESS] = dup_arc("operator less");
	d->string_type[TYPE_TOKEN_UNDEFINED] = dup_arc("token undefined");
	d->string_type[TYPE_TOKEN_LITERAL] = dup_arc("token literal");
	d->string_type[TYPE_TOKEN_OPERATOR] = dup_arc("token operator");
	d->string_type[TYPE_TOKEN_BLANK] = dup_arc("token blank");
	d->string_type[TYPE_TOKEN_LIMITER] = dup_arc("token limiter");
	d->string_type[TYPE_TOKEN_FILENAME] = dup_arc("token  filename");
	d->string_type[TYPE_TOKEN_COMMAND] = dup_arc("token  command");
	d->string_type[TYPE_TOKEN_ARGUMENT] = dup_arc("token  argument");
	check_dup_str();
}
