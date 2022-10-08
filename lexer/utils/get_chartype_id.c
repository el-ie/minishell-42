/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chartype_id.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:36:25 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 11:59:13 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief get the index of the state->type for the tokenisation
 * 			use case example :  state->type[get_chartype_id(state->prompt[0])]
 * @param c 
 * @return int 
 */
int	get_chartype_id(char c)
{
	if (c == '|'
		|| c == '&'
		|| c == ';'
		|| c == '('
		|| c == ')'
		|| c == '<'
		|| c == '>')
		return (1);
	if (c == ' ' || c == '\t')
		return (2);
	return (0);
}
