/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prompt_to_history.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:19:08 by apayet            #+#    #+#             */
/*   Updated: 2022/09/09 07:07:46 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*free_last_cmd(char *last_cmd)
{
	free(last_cmd);
	return ((char *)0);
}

static void	put_into_histfile(char *prompt)
{
	int		fd_histfile;
	char	*file;

	file = (char *)0;
	file = get_data((t_data *)0)->temporary_histfile;
	if (is_envp_empty() || file == (char *)0)
		return ;
	fd_histfile = -1;
	fd_histfile = open(file, O_RDWR | O_APPEND | O_CREAT, 0755);
	if (fd_histfile == -1)
		return ;
	write(fd_histfile, prompt, ft_strlen(prompt));
	write(fd_histfile, "\n", 1);
	close(fd_histfile);
}

/**
 * @brief 
 * 
 * @param prompt 
 * @param is_exiting set to one if want to clean the static 
 */
void	add_prompt_to_history(char *prompt, int is_exiting)
{
	static char	*last_cmd = (char *)0;
	char		*check_last_cmd;

	if (is_exiting)
	{
		last_cmd = free_last_cmd(&last_cmd[0]);
		return ;
	}
	check_last_cmd = (char *)0;
	if (ft_strlen(prompt) == 0)
		return ;
	if (last_cmd)
		check_last_cmd = ft_strnstr(prompt, last_cmd, ft_strlen(last_cmd));
	if (check_last_cmd != (char *)0 && ft_strlen(last_cmd) == ft_strlen(prompt))
		return ;
	free(last_cmd);
	last_cmd = (char *)0;
	last_cmd = ft_strdup(prompt);
	add_history(prompt);
	put_into_histfile(prompt);
}
