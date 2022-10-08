/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_all_lexer_token_t_list.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 07:47:58 by apayet            #+#    #+#             */
/*   Updated: 2022/09/20 09:16:29 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	printf_all_lexer_token_t_list(void)
{
	t_list			*lst;
	t_lexer_token	*token;

	if (DEBUG == FALSE)
		return ;
	printf("\nDEBUG : Start print after lexing the lexer token\n\n");
	lst = get_data((t_data *)0)->lexer_tokens;
	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		ft_printf("\ntoken->id :\t\t\t%d\n", token->id);
		ft_printf("token->type string :\t\t%s\n", get_type_to_string(token->type));
		ft_printf("token->type int : \t\t%d \n", token->type);
		ft_printf("token->value :\t\t\t\"");
		put_lexer_token_fd(token, 1);
		write(1, "\"\n\n", 2);
		lst = lst->next;
	}
	printf("\n\nEnd of the t_list of lexer-token\n");
}
