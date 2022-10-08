/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredoc_list_and_erase_file.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:52:09 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 16:29:10 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_heredoc_list_and_erase_file(void)
{
	t_list				*hdoc;
	t_list				*tmp;
	t_heredoc			*content;

	hdoc = get_data((t_data *)0)->here_doc_list;
	if (hdoc == (t_list *)0)
		return ;
	while (hdoc)
	{
		content = (t_heredoc *)hdoc->content;
		unlink(content->filename);
		free(content->filename);
		content->filename = (char *)0;
		free(content->limiter);
		content->limiter = (char *)0;
		tmp = hdoc;
		hdoc = hdoc->next;
		free(tmp);
	}
	get_data((t_data *)0)->here_doc_list = (t_list *)0;
}
