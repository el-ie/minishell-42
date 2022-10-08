/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_prompt_heredoc_from_list.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:32:36 by apayet            #+#    #+#             */
/*   Updated: 2022/10/06 00:26:08 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	request_prompt_heredoc_from_list(void)
{
	t_heredoc	*hdoc;
	t_list		*hdoc_lst;

	hdoc_lst = get_data((t_data *)0)->here_doc_list;
	while (hdoc_lst)
	{
		hdoc = (t_heredoc *)hdoc_lst->content;
		heredoc_prompt_writer(hdoc);
		hdoc_lst = hdoc_lst->next;
	}
	clean_exit(NULL);
}
