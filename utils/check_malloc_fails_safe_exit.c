/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc_fails_safe_exit.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:16:10 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 18:46:40 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function is designed to be executed just after a malloc 
 * 			it will exit the program if it fails
 * @param node the adress you want to check
 */
void	check_malloc_fails_safe_exit(void *node)
{
	if (node == (void *)0)
	{
		get_data((t_data *)0)->status_last_cmd = 1;
		perror("Malloc error");
		free_heredoc_list_and_erase_file();
		clean_exit((char *)0);
	}
}
