/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_program_folders.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:43:00 by apayet            #+#    #+#             */
/*   Updated: 2022/07/07 18:10:45 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief This function permit to set the program folders.
 * 
 */
void	set_program_folders(void)
{
	char	*folder;
	char	*temp;
	int		cursor;
	char	*(*join)(const char *, const char *);

	join = &ft_strjoin_arc;
	temp = get_data((t_data *)0)->main.argv[0];
	folder = ft_strdup_arc(temp);
	cursor = ft_strlen(folder) - 1;
	while (cursor > 0 && folder[cursor] != '/')
		cursor--;
	folder[cursor] = '\0';
	(get_data((t_data *)0))->program_folder = folder;
	(get_data((t_data *)0))->builtin_folder = join(folder, "/bin");
}
