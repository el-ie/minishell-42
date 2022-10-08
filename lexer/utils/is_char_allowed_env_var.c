/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_allowed_env_var.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 21:04:28 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:39:15 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_char_allowed_env_var(char c)
{
	return (ft_isuppercase(c)
		|| ft_isdigit(c)
		|| ft_is_underscore(c)
		|| ft_islowercase(c));
}
