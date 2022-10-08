/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_prelexed_to_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:09:22 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:34:38 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 
 * 
 * @param ref 
 * @param is_free_act 
 * @return char* 
 */
static char	*reg_local_garbage(char *ref, int is_free_act)
{
	static t_list	*local_garbage = (t_list *)0;

	if (is_free_act)
	{
		ft_lstclear(&local_garbage, &free);
		local_garbage = (t_list *)0;
		return ((char *)0);
	}
	else
		ft_lstadd_back(&local_garbage, ft_lstnew((void *)ref));
	return (ref);
}

static void	extract_literal(t_lexer_token *token, char **string, char **res)
{
	if (token->length > 0)
	{
		*string = reg_local_garbage(dup_token_to_str(token, 1), 0);
		*res = reg_local_garbage(ft_strjoin(*res, *string), 0);
	}
}

static int	is_var_last_status_cmd(char *str)
{
	if (ft_strlen(str) == 2 && str[1] == '?')
		return (1);
	return (0);
}

static void	extract_vars(t_lexer_token *tok, char **str, char **res, char **ev)
{
	char	*(*reg)(char *, int);
	char	*status;

	reg = &reg_local_garbage;
	status = (char *)0;
	if (tok->length > 1)
	{
		*str = reg(dup_token_to_str(tok, 1), 0);
		if (is_var_last_status_cmd(*str))
		{
			status = reg(ft_itoa(get_data((t_data *)0)->status_last_cmd), 0);
			*res = reg(ft_strjoin(*res, status), 0);
			return ;
		}
		*ev = get_env_value(&(str[0][1]));
		if (*ev)
		{
			*res = reg(ft_strjoin(*res, *ev), 0);
		}
	}
	else
	{
		*res = reg(ft_strjoin(*res, reg(ft_strdup("$"), 0)), 0);
	}
}

char	*convert_prelexed_to_str(t_list *list)
{
	t_lexer_token	*token;
	char			*string_part;
	char			*env;
	char			*res;
	char			*final_res;

	if (list == (t_list *)0)
		return ((char *)0);
	res = (char *)0;
	env = (char *)0;
	string_part = (char *)0;
	final_res = 0;
	res = reg_local_garbage(ft_strdup(""), 0);
	while (list)
	{
		token = (t_lexer_token *)list->content;
		if (token->type == TOKEN_TYPE_LITERAL)
			extract_literal(token, &string_part, &res);
		else if (token->type == TOKEN_TYPE_VARIABLE)
			extract_vars(token, &string_part, &res, &env);
		list = list->next;
	}
	final_res = reg_to_expand_lst(ft_strdup(res));
	reg_local_garbage((char *)0, 1);
	return (final_res);
}
