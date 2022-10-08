/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_op_of_redirect_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:37:01 by apayet            #+#    #+#             */
/*   Updated: 2022/10/04 12:49:35 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_op_of_redirect_fd(int type)
{
	return (type == OPERATOR_D_GREAT
		|| type == OPERATOR_GREAT
		|| type == OPERATOR_LESS);
}
