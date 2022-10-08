/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_env_var_token_fd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:14:04 by apayet            #+#    #+#             */
/*   Updated: 2022/09/20 13:58:43 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	display_splited_value_list(void *lexer_token)
{
	t_lexer_token	*token;

	token = (t_lexer_token *)lexer_token;
	printf("taille du sub-token %ld\n", token->length);
	put_lexer_token_fd(token, 1);
	ft_putchar_fd('\n', 1);
}

static void	display_t_var_env_token_fd(void *element)
{
	t_env_var_token	*env_token;

	if (DEBUG == FALSE)
		return ;
	fd(&env_token->var_name, 1);
	ft_putstr_fd("\n=>\n", 1);
	put_lexer_token_fd(&env_token->full_content, 1);
	ft_putchar_fd('\n', 1);
	if (env_token->splited_content != (t_list *)0)
	{
		ft_printf("####### A split value inside\n");
		ft_lstiter(env_token->splited_content, &display_splited_value_list);
		ft_printf("\n\n");
	}
	else
		ft_printf("####### NO SPLIT INSIDE THIS VALUE\n\n");
}
