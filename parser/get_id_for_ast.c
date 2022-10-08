/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_id_for_ast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:26:14 by apayet            #+#    #+#             */
/*   Updated: 2022/09/02 22:26:51 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Get the id for ast object
 * 			Notice reset it at end of the parser
 * @param reset true or false
 * @return int 
 */
int	get_id_for_ast(int reset)
{
	static int	id = -1;

	if (reset)
		id = -1;
	id += 1;
	return (id);
}
