/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_and_retokenize_string_part.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 08:28:31 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:38:35 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function determine inside this token if need to remove quotes
 * 
 * @param token 
 * @return int 
 */
static int	check_having_quotes_inside_token(t_lexer_token *token)
{
	int		i;

	i = 0;
	while (token->start_address[i]
		&& (token->start_address + i) < token->end_address)
	{
		if (is_char_double_quote(token->start_address[i])
			|| is_char_single_quote(token->start_address[i]))
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief This function return 0 if okay and -1 if an error
 * 
 * @param token 
 */
static int	do_remove(t_lexer_token *token)
{
	char	*old_string;

	old_string = dup_token_to_str(token, TRUE);
	token->start_address = remove_quotes(old_string);
	if (token->start_address == (char *)0)
	{
		free(old_string);
		old_string = (char *)0;
		return (-1);
	}
	token->end_address = token->start_address + ft_strlen(token->start_address);
	token->length = token->end_address - token->start_address;
	token->free_able = TRUE;
	return (0);
}

/**
 * @brief This function remove quote and retokennize if needed 
 * 			SET THE FREE_ABLE TO ONE IF NEEDED
 * 	return -1 if error and 0 if no error
 */
int	remove_quotes_and_retokenize_string_part(void)
{
	t_list			*lst;
	t_lexer_token	*token;

	lst = get_data((t_data *)0)->lexer_tokens;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (check_having_quotes_inside_token(token) == TRUE)
		{
			if (do_remove(token) == -1)
				return (-1);
		}
		lst = lst->next;
	}
	return (0);
}
