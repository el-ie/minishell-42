/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all_env_t_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:04:55 by apayet            #+#    #+#             */
/*   Updated: 2022/09/20 09:30:02 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	printf_all_env_t_list(void)
{
	t_list			*cur;
	t_env_var_token	*content;

	if (DEBUG == FALSE)
		return ;
	cur = get_env_t_list();
	if (cur == (t_list *)0)
		return ;
	while (cur)
	{
		content = (t_env_var_token *)cur->content;
		put_lexer_token_fd(&(content->var_name), 1);
		write(1, "=", 1);
		put_lexer_token_fd(&(content->full_content), 1);
		write(1, "\n", 1);
		cur = cur->next;
	}
	return ;
}
