/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:48:48 by apayet            #+#    #+#             */
/*   Updated: 2022/10/04 13:30:23 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*heredoc_handler(char *prompt)
{
	if (is_having_hdoc_inside_token_lst())
	{
		if (main_heredoc() == 0)
			return (free_the_prompt(&prompt));
	}
	return (prompt);
}

static char	*redirect_fd_handler(char *prompt)
{
	if (is_having_redirect_op_inside_list())
	{
		if (is_redirect_fd_having_filename())
			set_token_type_for_redirect_fd_filename();
		else
			return (free_the_prompt(&prompt));
	}
	return (prompt);
}

/**
 * @brief This is the funcction  who tokenize the string
 * @param prompt 
 */
char	*lexer(char	*prompt)
{
	char	*new_prompt;

	get_data((t_data *)0)->is_lexer_okay = FALSE;
	new_prompt = prelexer_for_expand_prompt(prompt);
	prompt = refresh_prompt_after_expand(&new_prompt, &prompt);
	tokenize_prompt(prompt);
	specify_token_type_operator();
	prompt = heredoc_handler(prompt);
	if (prompt == (char *)0)
		return ((char *)0);
	prompt = redirect_fd_handler(prompt);
	if (prompt == (char *)0)
		return ((char *)0);
	set_token_type_for_command();
	set_token_type_for_argument();
	if (check_subject_boundary_reserved_word())
		return (free_the_prompt(&prompt));
	if (remove_quotes_and_retokenize_string_part() == -1)
		return (free_the_prompt(&prompt));
	convert_token_limiter_to_token_filename();
	printf_all_lexer_token_t_list();
	get_data((t_data *)0)->is_lexer_okay = TRUE;
	return (prompt);
}
