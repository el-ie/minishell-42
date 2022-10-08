/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc_garbage_lst.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:58:12 by apayet            #+#    #+#             */
/*   Updated: 2022/08/26 18:07:05 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// Init inside reg_local_garbage and call for write the heredoc
t_list	*get_heredoc_garbage_lst(t_list *lst)
{
	static t_list	*ref_garbage = (t_list *)0;

	if (lst != (t_list *)0)
		ref_garbage = lst;
	return (ref_garbage);
}
