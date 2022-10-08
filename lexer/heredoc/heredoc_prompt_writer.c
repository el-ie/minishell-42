/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_prompt_writer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:28:26 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:40:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	iter_write_on_fd(void *content)
{
	write(get_fd_open(GET_FD_OPEN), (char *)content, ft_strlen(content));
	write(get_fd_open(GET_FD_OPEN), "\n", 1);
}

static void	iter_write_and_expand_on_fd(void *content)
{
	void	*to_write;

	if (hdoc_line_need_expand((char *)content))
		to_write = (void *)expand_heredoc(content);
	else
		to_write = content;
	iter_write_on_fd(to_write);
}

static int	is_limiter_founded(char *prompt, char *limiter)
{
	size_t	len_of_limiter;
	char	*result;

	result = (char *)0;
	len_of_limiter = ft_strlen(limiter);
	result = ft_strnstr(prompt, limiter, len_of_limiter);
	return (!(result == (char *)0) && ft_strlen(prompt) == len_of_limiter);
}

static void	do_the_loop(t_heredoc *hdoc, int save_count_line, int *counter)
{
	char	*prompt;

	while (1)
	{	
		prompt = readline("heredoc> ");
		if (prompt == (char *)0)
		{
			warn_heredoc_ctrl_d(hdoc, save_count_line);
			break ;
		}
		if (is_limiter_founded(prompt, hdoc->limiter))
		{
			counter += 1;
			break ;
		}
		counter += 1;
		reg_heredoc_garbage(prompt, FALSE);
	}
}

/**
 * @brief not expanded yet
 * 			
 * @param hdoc 
 */
void	heredoc_prompt_writer(t_heredoc *hdoc)
{
	int		fd;
	int		save_count_line;
	int		counter;
	t_list	*(*get_hdoc_gb)(t_list *);

	get_hdoc_gb = &get_heredoc_garbage_lst;
	save_count_line = get_previous_counted_line_from_file();
	counter = 0;
	fd = open(hdoc->filename, O_RDWR | O_CREAT, 0755);
	if (fd == -1)
	{
		perror("heredoc error");
		get_data((t_data *)0)->status_last_cmd = 1;
		clean_exit((char *)0);
	}
	get_fd_open(fd);
	do_the_loop(hdoc, save_count_line, &counter);
	set_previous_counted_line_from_file(counter);
	if (hdoc->expandable)
		ft_lstiter(get_hdoc_gb((t_list *)0), &iter_write_and_expand_on_fd);
	else
		ft_lstiter(get_hdoc_gb((t_list *)0), &iter_write_on_fd);
	reg_heredoc_garbage((char *)0, TRUE);
	get_fd_open(RESET_GET_FD_OPEN);
	close(fd);
}
