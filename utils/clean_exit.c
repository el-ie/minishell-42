/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:49:20 by apayet            #+#    #+#             */
/*   Updated: 2022/10/06 01:59:48 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clean_exit(char *prompt)
{
	free_heredoc_list();
	free_lexer_tokens();
	free_ast();
	get_control_string(TRUE);
	get_reserved_word_array(0, TRUE);
	if (get_data((t_data *)0)->error_on_terminal_cfg == 0)
		reset_terminal_config();
	add_prompt_to_history((char *)0, 1);
	free_prompt(&prompt);
	free_env_var_token();
	free_env_dupped(TRUE);
	clear_garbage();
	get_next_line(-1, TRUE);
	free_expand_lst();
	exit(get_data((t_data *)0)->status_last_cmd);
}
