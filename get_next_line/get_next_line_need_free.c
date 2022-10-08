/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_need_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 22:32:39 by apayet            #+#    #+#             */
/*   Updated: 2022/10/06 00:38:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_next_line_need_free(char **swap, int *last_l, int reset)
{
	if (reset == TRUE)
	{
		*last_l = 0;
		*swap = ft_free(*swap);
		return (*swap);
	}
	return (*swap);
}
