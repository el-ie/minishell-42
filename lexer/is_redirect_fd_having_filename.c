/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirect_fd_having_filename.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:34:37 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 21:08:33 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	display_error_filenname(t_list *lst, t_lexer_token *token)
{
	t_lexer_token	*token_after;

	ft_putstr_fd("minishell : parse error near unexpected token `", 2);
	token_after = (t_lexer_token *)0;
	token = get_next_lexer_token_not_blank(lst);
	if (lst->next)
		token_after = get_next_lexer_token_not_blank(lst->next);
	if (token && token_after != (t_lexer_token *)0)
	{
		put_lexer_token_fd(token, 2);
	}
	else
		ft_putstr_fd("newline", 2);
	ft_putstr_fd("'\n", 2);
	get_data((t_data *)0)->status_last_cmd = 2;
	return (0);
}

/**
 * @brief check before set the token to filename type
 * 
 * @return int return 0 if havingno filname
 */
int	is_redirect_fd_having_filename(void)
{
	t_list			*lst;
	t_lexer_token	*token;
	int				type;

	lst = get_data((t_data *)0)->lexer_tokens;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (is_op_of_redirect_fd(token->type))
		{
			type = get_next_token_type_from_lst_el(lst);
			if (type != TOKEN_TYPE_LITERAL || type == -1)
				return (display_error_filenname(lst, token));
		}
		lst = lst->next;
	}
	return (1);
}
