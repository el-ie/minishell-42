/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_loop_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:02:31 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 12:03:01 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_loop_main(char *prompt)
{
	free_heredoc_list_and_erase_file();
	free_ast();
	free_expand_lst();
	if (is_interactive_mode() == 0)
		clean_exit(prompt);
}
