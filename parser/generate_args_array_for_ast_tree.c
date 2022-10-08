/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_args_array_for_ast_tree.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:28:50 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 13:39:59 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/** 
 * @brief this function count the number of args the command have,
 * based on the lexer
 * length return count + 1
 * @param node a node of a token
 * @return size_t the number
 */
static int	get_args_array_length(t_list *node)
{
	int				count;
	t_lexer_token	*token;

	count = 0;
	while (node)
	{
		token = (t_lexer_token *)node->content;
		if (token->type == TOKEN_TYPE_ARGUMENT)
			count++;
		if (token->type == OPERATOR_PIPE)
			return (count);
		node = node->next;
	}
	return (count);
}

static void	gen_dup_token(char **array, int *i, t_lexer_token *token)
{
	array[*i] = dup_token_to_str(token, TRUE);
	*i = *i + 1;
}

static void	do_the_loop(t_list *lst, char **array, int *i)
{
	t_lexer_token	*token;

	while (lst)
	{
		token = (t_lexer_token *)lst->content;
		if (token->type == TOKEN_TYPE_ARGUMENT)
			gen_dup_token(array, i, token);
		if (token->type == OPERATOR_PIPE)
			break ;
		lst = lst->next;
	}
}

char	**generate_args_array_for_ast_tree(t_list *lst)
{
	char			**array;
	int				array_length;
	int				i;

	i = 0;
	array = (char **)0;
	array_length = get_args_array_length(lst);
	if (array_length == 0)
		return ((char **)0);
	array = (char **)ft_malloc(sizeof(char *) * (array_length + 1));
	check_malloc_fails_safe_exit((void *)array);
	do_the_loop(lst, array, &i);
	array[i] = (char *)0;
	return (array);
}
