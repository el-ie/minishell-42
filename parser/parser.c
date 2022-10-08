/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:52:12 by apayet            #+#    #+#             */
/*   Updated: 2022/09/21 13:40:59 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	do_parse(t_ast *ast, t_list *lst)
{
	set_id_to_ast_node(ast);
	set_ast_type_string_to_ast_node(ast, AST_TYPE_COMMAND);
	set_command_to_ast_node(ast, lst);
	set_args_to_ast_node(ast, lst);
	set_env_to_ast_node(ast);
	set_control_to_ast_node(ast);
	set_next_to_ast_node(ast);
	set_t_redirect_for_ast_node(ast, lst);
}

/**
 * @brief after the who has start created the structure,
 *  we populate the t_ast here
 *  * TOOLS : send current element
 * void	set_env_to_ast_node(t_ast *ast);
 * void	set_control_to_ast_node(t_ast *ast);
 * void	set_id_to_ast_node(t_ast *ast);
 * void	set_ast_type_string_to_ast_node(t_ast *ast, int ast_type)
 */
void	parser(void)
{
	t_ast	*ast;
	t_list	*lst;

	lst = get_data((t_data *)0)->lexer_tokens;
	if (lst == (t_list *)0)
		return ;
	if (get_data((t_data *)0)->is_lexer_okay == FALSE)
	{
		return ;
	}
	ast = create_node(NODE_TYPE_COMMAND);
	get_data((t_data *)0)->list_cmd = ast;
	while (lst)
	{
		do_parse(ast, lst);
		ast = go_to_t_redirect_for_ast_node(ast->redirects);
		lst = iter_lst_until_pipe(lst);
	}
	get_id_for_ast(TRUE);
}
