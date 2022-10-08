/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_display_prompt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:58:30 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 21:25:09 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_current_is_home_folder(void)
{
	char	*home_user;
	char	*current_folder;
	size_t	size_of_current_folder;

	home_user = (char *)0;
	current_folder = get_data((t_data *)0)->current_folder;
	size_of_current_folder = ft_strlen(current_folder);
	home_user = get_env_value("HOME");
	if (home_user == (char *)0)
		return (0);
	if (ft_strncmp(current_folder, home_user, size_of_current_folder) == 0)
		if (ft_strlen(home_user) == size_of_current_folder)
			return (1);
	return (0);
}

/**
 * @brief This function update the prompt folder
 * 
 */
static void	update_prompt_folder(void)
{
	char	*display;
	int		cursor;
	t_data	*data;

	data = get_data((t_data *)0);
	getcwd(&(get_data((t_data *)0)->current_folder)[0], 4096);
	if (is_current_is_home_folder())
	{
		get_data((t_data *)0)->prompt_display = ft_strdup_arc("~");
		return ;
	}
	display = ft_strdup_arc(get_data((t_data *)0)->current_folder);
	cursor = ft_strlen(display) - 1;
	if (cursor != 0)
	{
		while (cursor > 0 && display[cursor] != '/')
			cursor--;
		cursor = cursor + 1;
		data->prompt_display = ft_strdup_arc((const char *)&(display[cursor]));
	}
	else
		get_data((t_data *)0)->prompt_display = ft_strdup_arc("/");
}

/**
 * @brief Get the display prompt string, used inside readline
 * 
 * @return char* 
 */
char	*get_display_prompt(void)
{
	char	*first_part;
	char	*last_part;
	char	*result;

	first_part = (char *)0;
	last_part = (char *)0;
	result = (char *)0;
	update_prompt_folder();
	if (get_data((t_data *)0)->status_last_cmd == 0)
		first_part = ft_strdup_arc(\
		"\001\033[32m\002[V]\001\033[0m\002 minishell\001\033[36m\002 (");
	else
		first_part = ft_strdup_arc(\
		"\001\033[31m\002[X]\001\033[0m\002 minishell\001\033[36m\002 (");
	last_part = ft_strjoin_arc(get_data((t_data *)0)->prompt_display, \
		") \001\033[0m\002$ ");
	result = ft_strjoin_arc(first_part, last_part);
	return (result);
}
