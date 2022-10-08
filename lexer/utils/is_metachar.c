/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_metachar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:11:34 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:00:30 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Function to know if a char is a metachar as mentionned to
 * 			the man gnu bash
 * 
 * @param c the char we want to know.
 * @return int true of false (1 || 0)
 */
int	is_metachar(char c)
{
	return (c == '|'
		|| c == '&'
		|| c == ';'
		|| c == '('
		|| c == ')'
		|| c == '<'
		|| c == '>'
		|| c == ' '
		|| c == '\t'
		|| c == '\0');
}
