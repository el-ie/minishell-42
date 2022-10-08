/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_envp_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:24:23 by apayet            #+#    #+#             */
/*   Updated: 2022/09/13 12:37:21 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Must check minimal environnement
 * 
 * @return int 
 */
int	is_envp_empty(void)
{
	return (*get_env_addr() == (char *)0);
}
