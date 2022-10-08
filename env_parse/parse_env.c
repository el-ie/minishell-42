/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:47:58 by apayet            #+#    #+#             */
/*   Updated: 2022/10/05 17:06:31 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_env_var_token	*lex_env_line(char *line)
{
	t_env_var_token		*env_token;
	t_state_lex_env		env_cursors;

	ft_memset(&env_cursors, 0, sizeof(t_lexer_state));
	env_token = create_node(NODE_TYPE_ENV_VAR_TOKEN);
	check_malloc_fails_safe_exit((void *)env_token);
	env_token->var_name.start_address = line + env_cursors._name;
	env_cursors._name = count_until_char_found(line, '=');
	env_token->var_name.end_address = line + env_cursors._name;
	env_token->var_name.length = get_token_length(&(env_token->var_name));
	env_cursors._full = env_cursors._name;
	env_cursors._split = env_cursors._full;
	env_token->full_content.start_address = line + env_cursors._full + 1;
	env_cursors._full = count_until_char_found(line, '\0');
	env_token->full_content.end_address = line + env_cursors._full;
	env_token->full_content.length = \
	get_token_length(&(env_token->full_content));
	return (env_token);
}

void	parse_env(void)
{
	int		i;
	char	**env;

	i = 0;
	env = get_env_addr();
	if (env == (char **)0)
		return ;
	if (*env == (char *)0)
	{
		create_minimal_env();
		env = get_env_addr();
	}
	while (env[i])
	{
		ft_lstadd_back(&(get_data((t_data *)0)->list_env_token), \
		ft_lstnew((void *)lex_env_line(env[i])));
		i++;
	}
}
