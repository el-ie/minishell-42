/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:40:32 by apayet            #+#    #+#             */
/*   Updated: 2022/06/15 18:40:47 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_token(t_token *pin, int token_type, char *token_value)
{
	if (pin == (t_token *)0)
		return ;
	pin->type = get_type_to_string(token_type);
	pin->value = token_value;
}
