/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <apayet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:32:57 by apayet            #+#    #+#             */
/*   Updated: 2022/10/03 19:08:55 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief This function set the size of a malloc for avoid
 * 			usage of the if statement
 * 
 * 	The input is a pointer of an array who is on the stack of create node 
 * 
 * @depend on create_node
 * 
 */
static void	set_allocate_size_node_type(size_t *node_size_array)
{
	node_size_array[NODE_TYPE_COMMAND] = sizeof(t_ast);
	node_size_array[NODE_TYPE_TOKEN] = sizeof(t_token);
	node_size_array[NODE_TYPE_T_REDIRECT] = sizeof(t_redirect);
	node_size_array[NODE_TYPE_REDIRECT_FD] = sizeof(t_redirect_fd);
	node_size_array[NODE_TYPE_LEXER_TOKEN] = sizeof(t_lexer_token);
	node_size_array[NODE_TYPE_ENV_VAR_TOKEN] = sizeof(t_env_var_token);
	node_size_array[NODE_TYPE_HEREDOC] = sizeof(t_heredoc);
}

/**
 * @brief This function is designed to set if it is on garbadge or not
 * 			If a nnew node is created you must add here 
 * 			else it will be set to the garbage collector
 * 
 * @param node_type 
 * @return unsigned int 
 */
static unsigned int	is_on_garbage(int node_type)
{
	if (NODE_TYPE_LEXER_TOKEN == node_type
		|| NODE_TYPE_T_REDIRECT == node_type
		|| NODE_TYPE_ENV_VAR_TOKEN == node_type
		|| NODE_TYPE_COMMAND == node_type
		|| NODE_TYPE_REDIRECT_FD == node_type)
		return (0);
	return (1);
}

/**
 * @brief This function dynamically allocate the right size of a node
 * 			You can also add or not to the garbage collector 
 * 			See up for implementation.
 * 
 * @return void *
 */
void	*create_node(int node_type)
{
	void	*node;
	size_t	node_size[MAXIMUM_NODE_TYPE];
	void	*(*choice[2])(size_t);

	choice[0] = &malloc;
	choice[1] = &ft_malloc;
	node = (void *)0;
	set_allocate_size_node_type(&(*node_size));
	node = choice[is_on_garbage(node_type)](node_size[node_type]);
	check_malloc_fails_safe_exit(node);
	ft_memset(node, 0, node_size[node_type]);
	return (node);
}
