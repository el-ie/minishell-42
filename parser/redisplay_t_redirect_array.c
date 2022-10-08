/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redisplay_t_redirect_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:43:40 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 14:40:10 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	display_t_redirect_array(t_redirect **array)
{
	int				i;
	int				type;
	t_redirect_fd	*redirectfd;

	i = 0;
	if (DEBUG == FALSE)
		return ;
	printf("\n\nDEBUG : Visualize redirect_fd content\n");
	while (array[i])
	{
		type = array[i]->type;
		if (type > OPERATOR_PIPE && type < OPERATOR_MAX_VALUE)
		{
			redirectfd = (t_redirect_fd *)array[i]->content;
			ft_printf("\n\nNew element-----\nType : %d\n", redirectfd->type);
			ft_printf("fd : %d\n", redirectfd->type);
			ft_printf("op : %s\n", redirectfd->op);
			ft_printf("filename : %s\n", redirectfd->filename);
		}
		else
			break ;
		i++;
	}
}
