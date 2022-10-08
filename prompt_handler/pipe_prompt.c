/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:15:33 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 21:15:15 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// static char	*parent_process_read_child_writed(char *filename)
// {
// 	int		fd;
// 	char	*new_prompt;
// 	char	*res;

// 	res = (char *)0;
// 	fd = -1;
// 	fd = open(filename, O_RDONLY, 0755);
// 	if (fd < 0)
// 	{
// 		perror("open error : ");
// 		clean_exit((char *)0);
// 	}
// 	new_prompt = get_next_line(fd, 0);
// 	res = ft_strdup_arc(new_prompt);
// 	free(new_prompt);
// 	get_next_line(0, 1);
// 	close(fd);
// 	unlink(filename);
// 	res[ft_strlen(res) - 1] = '\0';
// 	return (res);
// }

// static void	child_ask_prompt(char *tmp_file, char *prompt)
// {
// 	int		fd;
// 	char	*tmp_prompt;

// 	fd = -1;
// 	tmp_prompt = (char *)0;
// 	fd = open(tmp_file, O_RDWR | O_CREAT, 0755);
// 	if (fd < 0)
// 	{
// 		perror("open error ");
// 		get_data((t_data *)0)->status_last_cmd = SIGINT;
// 		clean_exit(NULL);
// 	}
// 	ft_putstr_fd(prompt, fd);
// 	register_pipe_signal_handler();
// 	tmp_prompt = readline("pipe> ");
// 	if (tmp_prompt == (char *)0)
// 	{
// 		close(fd);
// 		get_data(NULL)->status_last_cmd = 1;
// 		clean_exit(NULL);
// 	}
// 	ft_putstr_fd(tmp_prompt, fd);
// 	ft_putstr_fd("\n", fd);
// 	close(fd);
// 	clean_exit(NULL);
// }

// static void	fork_error(char *prompt)
// {
// 	perror("multi-line pipe error ");
// 	get_data((t_data *)0)->status_last_cmd = 1;
// 	clean_exit(prompt);
// }

// char	*pipe_prompt(char *prompt)
// {
// 	return (prompt);
// }
