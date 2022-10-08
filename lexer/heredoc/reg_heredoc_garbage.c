/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_heredoc_garbage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:55:51 by apayet            #+#    #+#             */
/*   Updated: 2022/08/26 18:07:10 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*reg_heredoc_garbage(char *ref, int is_reset)
{
	static t_list	*collect = (t_list *)0;

	if (is_reset == 1)
	{
		ft_lstclear(&collect, &free);
		collect = (t_list *)0;
		return ((char *)0);
	}
	ft_lstadd_back(&collect, ft_lstnew((void *)ref));
	if (ft_lstsize(collect) == 1)
		get_heredoc_garbage_lst(collect);
	return (ref);
}
