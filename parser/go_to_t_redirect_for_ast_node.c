/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_t_redirect_for_ast_node.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:36:35 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 14:40:39 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ast	*go_to_t_redirect_for_ast_node(t_redirect **array)
{
	int			i;
	t_redirect	*redirect;

	i = 0;
	if (array == (t_redirect **)0)
		return ((t_ast *)0);
	while (array[i])
	{
		redirect = array[i];
		if (redirect->type == OPERATOR_PIPE)
			return ((t_ast *)redirect->content);
		i++;
	}
	return ((t_ast *)0);
}
