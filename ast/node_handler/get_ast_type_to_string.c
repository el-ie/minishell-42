/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ast_type_to_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:10:39 by apayet            #+#    #+#             */
/*   Updated: 2022/09/07 17:07:41 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_ast_type_to_string(int ast_type)
{
	return ((char *)get_data((t_data *)0)->string_ast_type[ast_type]);
}
