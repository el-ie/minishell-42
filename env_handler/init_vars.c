/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:17:41 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 19:19:11 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Called inside set_env_by_var_name
 * 
 * @param k_len 
 * @param f_key 
 * @param sub 
 * @param key 
 */
void	init_vars(size_t *k_len, int *f_key, int *sub, const char *key)
{
	*sub = 0;
	*k_len = ft_strlen(key);
	*f_key = 0;
}
