/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_history_from_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:18:03 by apayet            #+#    #+#             */
/*   Updated: 2022/09/09 07:09:28 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	loop_load(int fd_histfile)
{
	char	*tempo;
	char	*store;

	tempo = (char *)0;
	tempo = get_next_line(fd_histfile, 0);
	while (tempo != (char *)0)
	{
		store = ft_strndup(tempo, ft_strlen(tempo) - 1);
		add_history(store);
		free(tempo);
		tempo = (char *)0;
		free(store);
		store = (char *)0;
		tempo = get_next_line(fd_histfile, 0);
	}
	get_next_line(fd_histfile, 1);
}

void	load_history_from_file(void)
{
	int		fd_histfile;
	char	*file;

	file = get_data((t_data *)0)->temporary_histfile;
	if (is_envp_empty() || file == (char *)0)
		return ;
	fd_histfile = -1;
	fd_histfile = open(file, O_RDONLY);
	if (fd_histfile == -1)
		return ;
	loop_load(fd_histfile);
	close(fd_histfile);
}
