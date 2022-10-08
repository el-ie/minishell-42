/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_is_digit_set_content.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:23:42 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 19:24:09 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief call inside set_content_variable_prelex function
 * 
 */
void	case_is_digit_set_content(t_prelex_state *state)
{
	while (state->prompt[state->i])
	{
		if (state->prompt[state->i] == '?'
			&& state->prompt[state->i - 1] == '$')
		{
			state->i = state->i + 1;
			break ;
		}
		if (is_char_allowed_env_var(state->prompt[state->i]) == 1)
			state->i = state->i + 1;
		else
			break ;
	}
}
