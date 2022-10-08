/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env_var_lex_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:19:37 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 19:20:54 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*register_to_dup_env_lst(char *elem)
{
	ft_lstadd_back(&(get_data((t_data *)0)->env_dup_list), \
	ft_lstnew((void *)elem));
	return (elem);
}

void	new_env_var_lex_token(const char *key_or_value, t_lexer_token *tok)
{
	tok->length = ft_strlen(key_or_value);
	tok->start_address = register_to_dup_env_lst(ft_strdup(key_or_value));
	tok->end_address = tok->start_address + tok->length;
	tok->free_able = 1;
}
