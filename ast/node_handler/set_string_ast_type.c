/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_string_ast_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:57:54 by apayet            #+#    #+#             */
/*   Updated: 2022/09/07 17:15:20 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_string_ast_type(void)
{
	char	*(*dup_arc)(const char *);
	t_data	*d;

	dup_arc = &ft_strdup_arc;
	d = get_data((t_data *)0);
	d->string_ast_type[AST_TYPE_COMMAND] = dup_arc("command");
	d->string_ast_type[AST_TYPE_PIPE] = dup_arc("pipe");
}
