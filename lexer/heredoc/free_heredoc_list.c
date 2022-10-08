/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredoc_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:09:02 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:40:49 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Ccalled inside main loop of the program.
 * 
 */
void	free_heredoc_list(void)
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
